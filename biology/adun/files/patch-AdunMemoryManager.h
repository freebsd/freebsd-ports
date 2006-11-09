--- Kernel/AdunKernel/Headers/AdunKernel/AdunMemoryManager.h.orig	Tue Jun 13 12:16:44 2006
+++ Kernel/AdunKernel/Headers/AdunKernel/AdunMemoryManager.h	Sun Nov  5 13:16:58 2006
@@ -24,7 +24,9 @@
 #define _ADUNIOMANAGER_
 
 #include <stdlib.h>
+#ifndef __FreeBSD__
 #include <malloc.h>
+#endif
 #include "Base/InterTable.h"
 #include "AdunKernel/AdunDefinitions.h"
 #include "AdunKernel/AdunObject.h"
@@ -38,7 +40,9 @@
 
 @interface AdMemoryManager: AdObject 
 {
+#ifndef __FreeBSD__
 	struct mallinfo mem_struct;
+#endif
 	BOOL MEMORY_STATS;
 }
 
