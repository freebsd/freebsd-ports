--- calc/yydefines.h.orig	Thu Aug 20 23:49:19 1998
+++ calc/yydefines.h	Tue Mar  4 20:40:04 2003
@@ -7,9 +7,10 @@
 extern int parse_return_code;
 double gettime(char *);
 
-void yyrestart();
+#include <stdio.h>
+void yyrestart(FILE *);
 int yyerror(char *);
-int yylex();
+int yylex(void);
 char *yysave(char *);
 
 
