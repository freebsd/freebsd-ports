--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/m2c/rMemory.h	Tue Feb 15 14:26:55 1994
+++ ./reuse/m2c/rMemory.h	Thu Aug  5 18:49:34 2004
@@ -1,6 +1,10 @@
 #define DEFINITION_rMemory
 
+#ifndef DEFINITION_SYSTEM_
+#include "SYSTEM_.h"
+#endif
+
 extern LONGCARD rMemory_MemoryUsed;
 extern ADDRESS rMemory_Alloc ARGS((LONGINT ByteCount));
 extern void rMemory_Free ARGS((LONGINT ByteCount, ADDRESS a));
-extern void BEGIN_rMemory();
+extern void BEGIN_rMemory(NOARGS);
