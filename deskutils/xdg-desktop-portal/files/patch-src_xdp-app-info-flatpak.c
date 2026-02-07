--- src/xdp-app-info-flatpak.c.orig	2025-02-19 15:48:35 UTC
+++ src/xdp-app-info-flatpak.c
@@ -25,6 +25,7 @@
 
 #include <errno.h>
 #include <fcntl.h>
+#include <sys/mount.h>
 #ifdef HAVE_SYS_VFS_H
 #include <sys/vfs.h>
 #endif
@@ -643,6 +644,10 @@ open_flatpak_info (int      pid,
 open_flatpak_info (int      pid,
                    GError **error)
 {
+  g_set_error (error, XDP_APP_INFO_ERROR, XDP_APP_INFO_ERROR_WRONG_APP_KIND,
+                           "Certainly not a flatpak");
+  return -1;
+
   g_autofree char *root_path = NULL;
   g_autofd int root_fd = -1;
   g_autofd int info_fd = -1;
