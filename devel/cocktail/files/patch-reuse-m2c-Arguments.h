--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/m2c/Arguments.h	Tue Feb 15 14:26:45 1994
+++ ./reuse/m2c/Arguments.h	Thu Aug  5 18:49:33 2004
@@ -2,6 +2,10 @@
 
 #define DEFINITION_Arguments
 
+#ifndef DEFINITION_SYSTEM_
+#include "SYSTEM_.h"
+#endif
+
 typedef struct Arguments_1 {
     struct Arguments_2 {
         CHAR A[999 + 1];
@@ -10,4 +14,4 @@
 
 extern void GetArgs ARGS((SHORTCARD *argc, Arguments_ArgTable *argv));
 extern void GetEnv ARGS((Arguments_ArgTable *env));
-extern void BEGIN_Arguments();
+extern void BEGIN_Arguments(NOARGS);
