--- gate.h.orig	2005-01-24 06:24:26 UTC
+++ gate.h
@@ -211,7 +211,7 @@ int mv_file(char *src, char *dst);
 
 /* LINE.C */
 int outcol(char *str,int n,int icol);
-int getline(char *bf, char *wbf, int *wcol, char *prompt);
+int get_line(char *bf, char *wbf, int *wcol, char *prompt);
 void back_to_col(int ncol);
 void print_to_index(int newi);
 
