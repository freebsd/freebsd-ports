--- src/xdp-app-info-flatpak.c.orig	2025-02-19 15:48:35 UTC
+++ src/xdp-app-info-flatpak.c
@@ -25,6 +25,7 @@
 
 #include <errno.h>
 #include <fcntl.h>
+#include <sys/mount.h>
 #ifdef HAVE_SYS_VFS_H
 #include <sys/vfs.h>
 #endif
