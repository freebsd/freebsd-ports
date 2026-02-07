--- lib/i915/intel_memory_region.c.orig	2022-08-31 20:00:01 UTC
+++ lib/i915/intel_memory_region.c
@@ -21,7 +21,11 @@
  * IN THE SOFTWARE.
  */
 
+#ifdef __linux__
 #include <linux/limits.h>
+#elif defined(__FreeBSD__)
+#include <sys/limits.h>
+#endif
 #include <signal.h>
 #include <sys/ioctl.h>
 #include <sys/time.h>
