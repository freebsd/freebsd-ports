--- lib/igt_device.c.orig	2022-08-31 20:00:01 UTC
+++ lib/igt_device.c
@@ -25,7 +25,9 @@
 #include <fcntl.h>
 
 #include <sys/stat.h>
+#ifdef __linux__
 #include <sys/sysmacros.h>
+#endif
 #include "igt.h"
 #include "igt_device.h"
 #include "igt_sysfs.h"
