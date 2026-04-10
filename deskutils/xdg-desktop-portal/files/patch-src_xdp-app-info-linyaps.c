--- src/xdp-app-info-linyaps.c.orig	2026-06-17 16:46:28 UTC
+++ src/xdp-app-info-linyaps.c
@@ -26,6 +26,7 @@
 
 #include <errno.h>
 #include <fcntl.h>
+#include <sys/mount.h>
 
 #if HAVE_SYS_VFS_H
 #include <sys/vfs.h>
@@ -117,6 +118,10 @@ open_linyaps_info (int      pid,
   g_autofree char *root_path = NULL;
   g_autofd int root_fd = -1;
   g_autofd int info_fd = -1;
+
+  g_set_error (error, XDP_APP_INFO_ERROR, XDP_APP_INFO_ERROR_WRONG_APP_KIND,
+                           "Certainly not a linyaps");
+  return -1;
 
   root_path = g_strdup_printf ("/proc/%u/root", pid);
   root_fd = openat (AT_FDCWD, root_path, O_RDONLY | O_NONBLOCK | O_DIRECTORY | O_CLOEXEC | O_NOCTTY);
