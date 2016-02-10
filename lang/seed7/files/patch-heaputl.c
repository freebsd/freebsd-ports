--- heaputl.c.orig	2016-02-05 14:25:17 UTC
+++ heaputl.c
@@ -36,6 +36,7 @@
 
 #include "stdlib.h"
 #include "stdio.h"
+#include "stdint.h"
 #if HAS_GETRLIMIT && defined STACK_SIZE
 #include "sys/resource.h"
 #endif
