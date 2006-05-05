--- ./q_shared.h.orig	Thu May 19 17:56:13 2005
+++ ./q_shared.h	Sun Feb 26 11:25:24 2006
@@ -97,7 +97,16 @@
 typedef unsigned __int16 uint16;
 typedef unsigned __int64 uint64;
 #else /* NON-WIN32 */
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#if __FreeBSD_version < 500000
+#include <inttypes.h>
+#else
 #include <stdint.h>
+#endif
+#else
+#include <stdint.h>
+#endif
 typedef int32_t int32;
 typedef int16_t int16;
 typedef int64_t int64;
