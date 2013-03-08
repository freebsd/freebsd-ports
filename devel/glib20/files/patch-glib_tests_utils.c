--- glib/tests/utils.c.orig	2012-09-24 02:19:54.000000000 +0000
+++ glib/tests/utils.c	2012-09-24 02:20:48.000000000 +0000
@@ -416,7 +416,7 @@
 
   xdg = (gchar *)g_getenv ("XDG_CONFIG_DIRS");
   if (!xdg)
-    xdg = "/etc/xdg";
+    xdg = "/usr/local/etc/xdg:/etc/xdg";
 
   dirs = g_get_system_config_dirs ();
 
