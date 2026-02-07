--- lib/igt_device_scan.c.orig	2022-08-31 20:00:01 UTC
+++ lib/igt_device_scan.c
@@ -32,7 +32,11 @@
 #include <fcntl.h>
 #include <glib.h>
 #include <libudev.h>
+#ifdef __linux__
 #include <linux/limits.h>
+#elif defined(__FreeBSD__)
+#include <limits.h>
+#endif
 #include <sys/stat.h>
 #include <sys/time.h>
 #include <sys/types.h>
