--- heaputl.c.orig	2015-08-29 06:55:33 UTC
+++ heaputl.c
@@ -37,6 +37,7 @@
 #include "stdlib.h"
 #include "stdio.h"
 #if HAS_GETRLIMIT && defined STACK_SIZE
+#include "sys/types.h"
 #include "sys/resource.h"
 #endif
 
