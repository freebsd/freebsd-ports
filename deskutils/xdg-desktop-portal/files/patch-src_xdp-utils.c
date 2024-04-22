Make it possible to run firefox with KDE filedialogs.

The call for parse_app_info_from_flatpak_info uses the /proc/$PID/root
file to access the flatpak information file.

We neither have support for /proc/$PID/root nor flatpaks or snaps.

With this fix and deskutils/plasma5-xdg-desktop-portal-kde it is now possible
to run firefox using the KDE file dialogs.

> GTK_USE_PORTAL=1 firefox

--- src/xdp-utils.c.orig	2023-11-22 21:48:20 UTC
+++ src/xdp-utils.c
@@ -587,6 +587,7 @@ parse_app_info_from_flatpak_info (int pid, GError **er
 static XdpAppInfo *
 parse_app_info_from_flatpak_info (int pid, GError **error)
 {
+#ifndef __FreeBSD__
   g_autofree char *root_path = NULL;
   int root_fd = -1;
   int info_fd = -1;
@@ -689,6 +690,9 @@ parse_app_info_from_flatpak_info (int pid, GError **er
   app_info->u.flatpak.keyfile = g_steal_pointer (&metadata);
 
   return g_steal_pointer (&app_info);
+#else
+  return NULL;
+#endif // __FreeBSD__
 }
 
 int
