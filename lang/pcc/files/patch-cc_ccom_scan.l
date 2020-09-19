--- cc/ccom/scan.l.orig	2014-10-12 17:39:26 UTC
+++ cc/ccom/scan.l
@@ -236,7 +236,8 @@ L?\"(\\.|[^\\"])*\"	{ yylval.strp = yytext; return C_S
 
 %%
 
-int lineno, issyshdr;
+extern int lineno;
+int issyshdr;
 char *ftitle = "<stdin>";
 
 int
