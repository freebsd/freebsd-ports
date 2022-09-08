--- lib/i915/perf.c.orig	2022-08-31 20:00:01 UTC
+++ lib/i915/perf.c
@@ -29,7 +29,9 @@
 #include <fcntl.h>
 #include <sys/ioctl.h>
 #include <sys/stat.h>
+#ifdef __linux__
 #include <sys/sysmacros.h>
+#endif
 #include <sys/types.h>
 #include <unistd.h>
 
