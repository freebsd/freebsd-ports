--- lib/igt_sysfs.c.orig	2022-08-31 20:00:01 UTC
+++ lib/igt_sysfs.c
@@ -24,7 +24,9 @@
 
 #include <inttypes.h>
 #include <sys/stat.h>
+#ifdef __linux__
 #include <sys/sysmacros.h>
+#endif
 #include <sys/mount.h>
 #include <errno.h>
 #include <stdarg.h>
