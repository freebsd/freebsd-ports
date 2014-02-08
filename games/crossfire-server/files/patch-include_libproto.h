--- include/libproto.h.orig	2012-03-18 06:31:46.000000000 +0000
+++ include/libproto.h
@@ -441,7 +441,7 @@ extern void yypop_buffer_state(void);
 extern int yyget_lineno(void);
 extern FILE *yyget_in(void);
 extern FILE *yyget_out(void);
-extern int yyget_leng(void);
+extern size_t yyget_leng(void);
 extern char *yyget_text(void);
 extern void yyset_lineno(int line_number);
 extern void yyset_in(FILE *in_str);
