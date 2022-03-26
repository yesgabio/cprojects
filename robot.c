# cprojects
projects .c
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main()
{
    setlocale (LC_ALL, "Portuguese");
    char robo[10][10];
    int lini=0, cini=0, lfin=0, cfin=0, lcam=0, ccam=0, l=0, c=0, t=1;
    printf("Insira os pontos de início e fim do caminho do robô nas linhas e colunas entre 0 e 9. \n");
    printf("Você não poderá utilizar a posição linha 5 e coluna 5, neste local encontra-se um buraco! \n");
    printf("\n");
        for(l=0;l<10;l++){
            for(c=0;c<10;c++){
                robo[l][c] = '#';
            }
        }
        do{
    printf("Digite a posição inicial do robô: \n");
    printf("Linha: ");
    scanf("%i", &lini);
    printf("Coluna: ");
    scanf("%i", &cini);
    printf("Digite a posição final do robô: \n");
    printf("Linha: ");
    scanf("%i", &lfin);
    printf("Coluna: ");
    scanf("%i", &cfin);
        if (((lini==5)&&(cini==5))||((lfin==5)&&(cfin==5))){
        printf("HEY! Você digitou o local do buraco!! selecione os pontos novamente.\n");
        printf("\n");
        }
        if ((lini<0)||(lfin<0)||(lini>9)||(lfin>9)||(cini<0)||(cfin<0)||(cini>9)||(cfin>9)){
        printf("HEY! Você digitou os pontos fora do limite!! selecione os pontos novamente.\n");
        printf("\n");
        }
        }while (((lini==5)&&(cini==5))||((lfin==5)&&(cfin==5))||(lini<0)||(lfin<0)||(lini>9)||(lfin>9)||(cini<0)||(cfin<0)||(cini>9)||(cfin>9));
    lcam = lini;
    ccam = cini;
    while (t == 1){
                if ((lcam<lfin)&&(ccam<cfin)){
                    if ((lcam==5)&&(ccam==5)){
                        lcam++;
                        robo[(lcam-1)][(ccam-1)] = 'X';
                    }
                    else{
                        lcam++;
                        ccam++;
                    }
                robo[lcam][ccam] = 'X';
                }
                if ((lcam>lfin)&&(ccam>cfin)){
                    if ((lcam==5)&&(ccam==5)){
                        ccam--;
                        robo[(lcam+1)][(ccam+1)] = 'X';
                    }
                    else{
                        lcam--;
                        ccam--;
                    }
                robo[lcam][ccam] = 'X';
                }
                if ((lcam<lfin)&&(ccam>cfin)){
                    if ((lcam==5)&&(ccam==5)){
                        ccam--;
                    }
                    else{
                        lcam++;
                        ccam--;
                    }
                robo[lcam][ccam] = 'X';
                }
                if ((lcam>lfin)&&(ccam<cfin)){
                    if ((lcam==5)&&(ccam==5)){
                        lcam--;
                    }
                    else{
                        lcam--;
                        ccam++;
                    }
                robo[lcam][ccam] = 'X';
                }
                if ((lcam==lfin)&&(ccam<cfin)){
                    if ((lcam==5)&&(ccam==5)){
                        lcam--;
                    }
                    else{
                        lcam = lfin;
                        ccam++;
                    }
                robo[lcam][ccam] = 'X';
                }
                if ((lcam==lfin)&&(ccam>cfin)){
                    if ((lcam==5)&&(ccam==5)){
                        ccam++;
                    }
                    else{
                        lcam = lfin;
                        ccam--;
                    }
                robo[lcam][ccam] = 'X';
                }
                if ((lcam<lfin)&&(ccam==cfin)){
                    if ((lcam==5)&&(ccam==5)){
                        ccam++;
                    }
                    else{
                        lcam++;
                        ccam = cfin;
                    }
                robo[lcam][ccam] = 'X';
                }
                if ((lcam>lfin)&&(ccam==cfin)){
                    if ((lcam==5)&&(ccam==5)){
                        ccam++;
                    }
                    else{
                        lcam--;
                        ccam = cfin;
                    }
                robo[lcam][ccam] = 'X';
                }
                if ((lcam == lfin)&&(ccam == cfin)){
                t=0;
                }
    }
    robo[lini][cini] = 'A';
    robo[lfin][cfin] = 'B';
    robo[5][5] = 'O';
    printf("\nESSE FOI O CAMINHO DO SEU ROBÔ: \n");
    printf("\n");
        for(l=0;l<10;l++){
            for(c=0;c<10;c++){
                printf(" %c ", robo[l][c]);
            }
        printf("\n");
        }
    printf("\nLegenda:\n");
    printf("A: Ponto inicial \nB: Ponto final \nO: Buraco \nX: Caminho do robô \n#: Espaços limites");
}
