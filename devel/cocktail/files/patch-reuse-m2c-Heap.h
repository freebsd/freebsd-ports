--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/m2c/Heap.h	Tue Feb 15 14:26:51 1994
+++ ./reuse/m2c/Heap.h	Thu Aug  5 18:49:33 2004
@@ -1,6 +1,10 @@
 #define DEFINITION_Heap
 
+#ifndef DEFINITION_SYSTEM_
+#include "SYSTEM_.h"
+#endif
+
 extern LONGCARD Heap_HeapUsed;
 extern ADDRESS Heap_Alloc ARGS((LONGINT ByteCount));
-extern void Heap_Free ARGS(());
-extern void BEGIN_Heap();
+extern void Heap_Free  ARGS((NOARGS));
+extern void BEGIN_Heap(NOARGS);
