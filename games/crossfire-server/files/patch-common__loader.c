--- ./common/loader.c.orig	2012-03-19 06:14:09.000000000 +0100
+++ ./common/loader.c	2014-03-27 18:59:52.056923524 +0100
@@ -2898,7 +2898,7 @@
 
 void yyset_out  (FILE * out_str  );
 
-int yyget_leng (void );
+size_t yyget_leng (void );
 
 char *yyget_text (void );
 
@@ -5523,7 +5523,7 @@
 /** Get the length of the current token.
  * 
  */
-int yyget_leng  (void)
+size_t yyget_leng  (void)
 {
         return yyleng;
 }
