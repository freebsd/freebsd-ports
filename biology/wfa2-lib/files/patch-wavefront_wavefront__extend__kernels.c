--- wavefront/wavefront_extend_kernels.c.orig	2023-09-29 17:25:17 UTC
+++ wavefront/wavefront_extend_kernels.c
@@ -29,7 +29,7 @@
  * DESCRIPTION: WFA module for the "extension" of exact matches
  */
 
-#include <endian.h>
+#include <sys/endian.h>
 
 #include "wavefront_extend_kernels.h"
 #include "wavefront_termination.h"
