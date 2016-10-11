--- wmtictactoe.c.orig	1999-08-30 14:25:10 UTC
+++ wmtictactoe.c
@@ -123,7 +123,7 @@ int     wmtictactoe_mask_height = 64;
 // ----------------------------------------------------------
 // declaracao das funcoes do sistema
 
-void    main (int argc, char *argv[]);
+int    main (int argc, char *argv[]);
 void    usage (void);
 void    printversion (void);
 void    readfile (void);
@@ -168,7 +168,7 @@ void    game_over (void);
 //        in: argc - numero de argumentos passados por linha d comando
 //            argv - vetor com os argumentos
 //       out: nada
-void main (int argc, char *argv[])
+int main (int argc, char *argv[])
 {
 	int     i;
      
@@ -544,7 +544,7 @@ escreve_placar ()
         int coluna_xpm = 65;
 	int coluna_score[6] = 
 	{8, 15, 26, 33, 43, 50 };
-        char placar[6];
+        char placar[7];
 
   	if (isDeadmatch){
     		copyXPMArea(97, 74, 13, 9, 43, 88);
