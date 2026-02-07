--- lib/igt_kms.c.orig	2022-08-31 20:00:01 UTC
+++ lib/igt_kms.c
@@ -43,6 +43,10 @@
 #include <sys/kd.h>
 #endif
 
+#ifdef __FreeBSD__
+#include <sys/consio.h>
+#endif
+
 #include <libudev.h>
 #include <poll.h>
 #include <errno.h>
