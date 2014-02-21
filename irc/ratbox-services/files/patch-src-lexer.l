--- src/lexer.l.orig	2014-02-21 09:53:24.569248191 -0600
+++ src/lexer.l	2014-02-21 09:53:27.494247058 -0600
@@ -44,7 +44,7 @@
 int yyget_lineno(void);
 FILE *yyget_in(void);
 FILE *yyget_out(void);
-int yyget_leng(void);
+size_t yyget_leng(void);
 char *yyget_text(void);
 void yyset_lineno(int  line_number);
 void yyset_in(FILE *  in_str);
