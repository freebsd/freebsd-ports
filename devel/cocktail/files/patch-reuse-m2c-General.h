--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/m2c/General.h	Tue Feb 15 14:26:50 1994
+++ ./reuse/m2c/General.h	Thu Aug  5 18:49:33 2004
@@ -1,5 +1,9 @@
 #define DEFINITION_General
 
+#ifndef DEFINITION_SYSTEM_
+#include "SYSTEM_.h"
+#endif
+
 extern INTEGER General_MaxAlign;
 extern struct General_1 {
     BITSET A[16 + 1];
@@ -10,4 +14,4 @@
 extern LONGINT General_Exp2 ARGS((CARDINAL x));
 extern CARDINAL General_AntiLog ARGS((LONGINT x));
 extern REAL General_Exp10 ARGS((INTEGER x));
-extern void BEGIN_General();
+extern void BEGIN_General(NOARGS);
