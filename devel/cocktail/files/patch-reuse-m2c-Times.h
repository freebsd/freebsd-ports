--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/m2c/Times.h	Tue Feb 15 14:27:03 1994
+++ ./reuse/m2c/Times.h	Thu Aug  5 18:49:34 2004
@@ -1,6 +1,10 @@
 #define DEFINITION_Times
 
-extern LONGINT Times_CpuTime ARGS(());
-extern LONGINT Times_StepTime ARGS(());
+#ifndef DEFINITION_SYSTEM_
+#include "SYSTEM_.h"
+#endif
+
+extern LONGINT Times_CpuTime  ARGS((NOARGS));
+extern LONGINT Times_StepTime  ARGS((NOARGS));
 extern void Times_WriteStepTime ARGS((CHAR Text[], LONGCARD ));
-extern void BEGIN_Times();
+extern void BEGIN_Times(NOARGS);
