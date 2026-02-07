--- tools/preload.c.orig	2025-11-18 14:35:27 UTC
+++ tools/preload.c
@@ -33,7 +33,11 @@
 #include <sys/ioctl.h>
 #include <sys/stat.h>
 #include <sys/types.h>
+#ifdef __FreeBSD__
+#include <sys/extattr.h>
+#else
 #include <sys/xattr.h>
+#endif
 #include <unistd.h>
 
 typedef char IOCTL_BUF[4096];
