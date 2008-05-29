--- bf.h.orig	2008-05-29 20:46:45.000000000 +0200
+++ bf.h	2008-05-29 20:47:02.000000000 +0200
@@ -1,3 +1,5 @@
+#include <stdio.h>
+
 void emmit(char * s);
 extern int yyparse();
 extern FILE * yyin;
