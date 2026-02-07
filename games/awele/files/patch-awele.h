--- awele.h.orig	2020-08-27 20:02:51 UTC
+++ awele.h
@@ -14,7 +14,7 @@
 #define DEFAULT_FILENAME "awele.save"
 
 /* nom du fichier de sauvegarde */
-char nomfich[80] ;
+extern char nomfich[80] ;
 
 typedef struct {
     char board[TOTAL_SIZE] ; /* l'echiquier */
