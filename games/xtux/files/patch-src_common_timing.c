--- src/common/timing.c.orig	Mon Feb 17 12:10:07 2003
+++ src/common/timing.c	Thu May 15 20:03:11 2003
@@ -1,6 +1,12 @@
 #include <sys/time.h>
 #include <unistd.h>
+#include <sys/param.h>
+#if __FreeBSD_version >= 500000
 #include <stdint.h>
+#else
+#include <limits.h>
+#define INT32_MAX INT_MAX
+#endif
 #include "timing.h"
 
 static msec_t tvtol(struct timeval t);
