--- ./include/libproto.h.orig	2012-03-18 07:31:46.000000000 +0100
+++ ./include/libproto.h	2014-03-27 18:59:52.056923524 +0100
@@ -441,7 +441,7 @@
 extern int yyget_lineno(void);
 extern FILE *yyget_in(void);
 extern FILE *yyget_out(void);
-extern int yyget_leng(void);
+extern size_t yyget_leng(void);
 extern char *yyget_text(void);
 extern void yyset_lineno(int line_number);
 extern void yyset_in(FILE *in_str);
