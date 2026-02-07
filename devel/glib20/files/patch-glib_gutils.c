--- glib/gutils.c.orig	2020-12-17 11:47:11 UTC
+++ glib/gutils.c
@@ -2500,7 +2500,7 @@ g_build_system_data_dirs (void)
    */
 #ifndef G_OS_WIN32
   if (!data_dirs || !data_dirs[0])
-    data_dirs = "/usr/local/share/:/usr/share/";
+    data_dirs = "%%LOCALBASE%%/share/:/usr/share/";
 
   data_dir_vector = g_strsplit (data_dirs, G_SEARCHPATH_SEPARATOR_S, 0);
 #else
@@ -2594,7 +2594,7 @@ g_build_system_config_dirs (void)
     }
 #else
   if (!conf_dirs || !conf_dirs[0])
-    conf_dirs = "/etc/xdg";
+    conf_dirs = "%%LOCALBASE%%/etc/xdg:/etc/xdg";
 
   conf_dir_vector = g_strsplit (conf_dirs, G_SEARCHPATH_SEPARATOR_S, 0);
 #endif
