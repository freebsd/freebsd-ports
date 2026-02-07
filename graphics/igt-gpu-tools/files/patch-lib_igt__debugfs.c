--- lib/igt_debugfs.c.orig	2022-08-31 20:00:01 UTC
+++ lib/igt_debugfs.c
@@ -25,7 +25,9 @@
 #include <inttypes.h>
 #include <sys/stat.h>
 #include <sys/mount.h>
+#ifdef __linux__
 #include <sys/sysmacros.h>
+#endif
 #include <dirent.h>
 #include <errno.h>
 #include <stdio.h>
@@ -42,6 +44,10 @@
 #include "igt_kms.h"
 #include "igt_debugfs.h"
 #include "igt_sysfs.h"
+
+#ifdef __FreeBSD__
+#define	mount(src, dest, fstype, flags, data)	mount(fstype, dest, flags, data)
+#endif
 
 /**
  * SECTION:igt_debugfs
