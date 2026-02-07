--- bf.y.orig	2014-02-13 14:19:06.000000000 +0100
+++ bf.y	2014-02-13 14:19:18.000000000 +0100
@@ -20,6 +20,7 @@
 	| PUTC {process("putchar(array[p]);");}
 %%
 #include "bf.h"
+extern int yylex (void);
 
 int process(char * string) {
 	emmit(string);
