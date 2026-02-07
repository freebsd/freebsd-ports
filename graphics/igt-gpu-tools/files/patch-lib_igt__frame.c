--- lib/igt_frame.c.orig	2022-08-31 20:00:01 UTC
+++ lib/igt_frame.c
@@ -24,6 +24,10 @@
  *  Paul Kocialkowski <paul.kocialkowski@linux.intel.com>
  */
 
+#ifdef __FreeBSD__
+#include <limits.h>
+#endif
+
 #include "config.h"
 
 #include <fcntl.h>
