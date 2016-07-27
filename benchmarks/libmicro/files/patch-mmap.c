--- mmap.c.orig	2011-05-11 00:58:23 UTC
+++ mmap.c
@@ -28,6 +28,7 @@
  * Use is subject to license terms.
  */
 
+#include <sys/types.h>
 #include <sys/mman.h>
 #include <unistd.h>
 #include <stdlib.h>
