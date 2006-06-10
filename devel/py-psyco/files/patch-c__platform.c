#
# 4.x require sys/types.h to mmap()
#
--- ./c/platform.c.orig	Fri May 26 17:45:34 2006
+++ ./c/platform.c	Fri May 26 17:45:51 2006
@@ -32,6 +32,7 @@
 /************************************************************/
 
 #include <stdlib.h>
+#include <sys/types.h>
 #include <sys/mman.h>
 #if defined(MAP_ANON) && !defined(MAP_ANONYMOUS)
 #  define MAP_ANONYMOUS  MAP_ANON
