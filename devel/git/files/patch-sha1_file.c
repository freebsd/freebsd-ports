--- ./sha1_file.c.orig	2011-03-28 17:00:02.865270487 -0400
+++ ./sha1_file.c	2011-03-28 17:00:12.808276910 -0400
@@ -6,6 +6,7 @@
  * This handles basic git sha1 object files - packing, unpacking,
  * creation etc.
  */
+#include <sys/resource.h>
 #include "cache.h"
 #include "delta.h"
 #include "pack.h"
