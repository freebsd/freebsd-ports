--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/m2c/SetsC.h	Tue Feb 15 14:26:58 1994
+++ ./reuse/m2c/SetsC.h	Thu Aug  5 18:49:34 2004
@@ -1,5 +1,9 @@
 #define DEFINITION_SetsC
 
+#ifndef DEFINITION_SYSTEM_
+#include "SYSTEM_.h"
+#endif
+
 #ifndef DEFINITION_IO
 #include "IO.h"
 #endif
@@ -42,4 +46,4 @@
 extern void SetsC_ForallDo ARGS((SetsC_tSet Set, SetsC_ProcOfCard Proc));
 extern void SetsC_ReadSet ARGS((IO_tFile f, SetsC_tSet *Set));
 extern void SetsC_WriteSet ARGS((IO_tFile f, SetsC_tSet Set));
-extern void BEGIN_SetsC();
+extern void BEGIN_SetsC(NOARGS);
