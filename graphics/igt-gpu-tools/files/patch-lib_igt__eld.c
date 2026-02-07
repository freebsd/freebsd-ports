--- lib/igt_eld.c.orig	2022-08-31 20:00:01 UTC
+++ lib/igt_eld.c
@@ -23,6 +23,10 @@
  * Authors: Simon Ser <simon.ser@intel.com>
  */
 
+#ifdef __FreeBSD__
+#include <limits.h>
+#endif
+
 #include "config.h"
 
 #include <dirent.h>
