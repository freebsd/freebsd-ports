--- src/xdp-app-info-flatpak.c.orig	2026-06-17 16:46:28 UTC
+++ src/xdp-app-info-flatpak.c
@@ -27,6 +27,7 @@
 
 #include <errno.h>
 #include <fcntl.h>
+#include <sys/mount.h>
 
 #include <json-glib/json-glib.h>
 
@@ -645,6 +646,10 @@ open_flatpak_info (int      pid,
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
