--- l_memory.c.orig	Sat Jan 15 20:19:09 2005
+++ l_memory.c	Sat Jan 15 20:19:04 2005
@@ -10,11 +10,12 @@
 // Tab Size:     3
 //===========================================================================
 
-#include <malloc.h>
+#include <stdlib.h>
 #include "qcc.h"
 #include "l_log.h"
 
 
+#if 0
 /*
 =================
 MemorySize
@@ -31,6 +32,7 @@
  #endif
 #endif
 } //end of the function MemorySize
+#endif
 
 /*
 =================
