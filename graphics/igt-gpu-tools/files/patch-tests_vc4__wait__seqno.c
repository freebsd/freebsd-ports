--- tests/vc4_wait_seqno.c.orig	2022-08-31 20:00:01 UTC
+++ tests/vc4_wait_seqno.c
@@ -33,6 +33,10 @@
 #include <sys/ioctl.h>
 #include "vc4_drm.h"
 
+#ifdef __FreeBSD__
+#define	ETIME	ETIMEDOUT
+#endif
+
 igt_main
 {
 	int fd;
