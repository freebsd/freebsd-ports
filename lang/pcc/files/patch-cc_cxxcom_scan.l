--- cc/cxxcom/scan.l.orig	2014-08-18 11:27:34 UTC
+++ cc/cxxcom/scan.l
@@ -220,7 +220,8 @@ L?\"(\\.|[^\\"])*\"	{ yylval.strp = yytext; return C_S
 
 %%
 
-int lineno, issyshdr;
+extern int lineno;
+int issyshdr;
 char *ftitle = "<stdin>";
 
 static int
