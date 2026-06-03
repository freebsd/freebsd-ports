--- glib/tests/utils-unisolated.c.orig	2025-12-08 15:46:06 UTC
+++ glib/tests/utils-unisolated.c
@@ -81,7 +81,7 @@ test_xdg_dirs (void)
 
   xdg = (gchar *)g_getenv ("XDG_CONFIG_DIRS");
   if (!xdg)
-    xdg = "/etc/xdg";
+    xdg = "%%LOCALBASE%%/etc/xdg:/etc/xdg";
 
   dirs = g_get_system_config_dirs ();
 
