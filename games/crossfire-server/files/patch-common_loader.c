--- common/loader.c.orig	2012-03-19 05:14:09.000000000 +0000
+++ common/loader.c
@@ -2898,7 +2898,7 @@ FILE *yyget_out (void );
 
 void yyset_out  (FILE * out_str  );
 
-int yyget_leng (void );
+size_t yyget_leng (void );
 
 char *yyget_text (void );
 
@@ -5523,7 +5523,7 @@ FILE *yyget_out  (void)
 /** Get the length of the current token.
  * 
  */
-int yyget_leng  (void)
+size_t yyget_leng  (void)
 {
         return yyleng;
 }
