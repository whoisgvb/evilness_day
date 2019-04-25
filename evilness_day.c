#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){

    char* arq_original = argv[1];
    char* arq_mod = argv[2];

    printf("Gerando %s, de %s\n\n", arq_mod, arq_original);

    FILE* original = fopen(arq_original, "r");

    if(original == NULL){
        printf("Arquivo inválido!\n");
        return 0;
    }

    FILE* modificado = fopen(arq_mod, "w");

    if(modificado == NULL){
        printf("Não foi possivel abrir o arquivo modificado!\n");
        return 0;
    }

    char arq_atual_original[70];

    printf("Iniciando a malvadeza...\n");

    while( (fgets(arq_atual_original, sizeof(arq_atual_original), original)) != NULL){

        printf("Lendo: %s\n", arq_atual_original);
        int arq_original_tam = strlen(arq_atual_original);
        
        if(arq_atual_original[arq_original_tam - 2] == ';'){
            
            arq_atual_original[arq_original_tam - 2] = '\0';
            strcat(arq_atual_original, "\u037E\n");
            printf("Linha modificada: %s\n", arq_atual_original);
        }

        fputs(arq_atual_original, modificado);
        memset(arq_atual_original, '\0', sizeof(arq_atual_original));

    }
    

    fclose(original);
    free(original);
    free(arq_original);
    fclose(modificado);
    free(arq_mod);
    free(modificado);

    printf("Processo finalizado =)\n");
 

    return 1;
}