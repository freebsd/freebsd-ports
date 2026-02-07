--- tests/vc4_wait_bo.c.orig	2022-08-31 20:00:01 UTC
+++ tests/vc4_wait_bo.c
@@ -34,6 +34,10 @@
 #include <sys/ioctl.h>
 #include "vc4_drm.h"
 
+#ifdef __FreeBSD__
+#define	ETIME	ETIMEDOUT
+#endif
+
 static void
 test_used_bo(int fd, uint64_t timeout)
 {
