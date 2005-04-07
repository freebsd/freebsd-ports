--- glib/gutils.c.orig	Wed Mar 23 09:55:02 2005
+++ glib/gutils.c	Thu Apr  7 01:06:16 2005
@@ -1929,7 +1929,7 @@ g_get_system_data_dirs (void)
       data_dirs = (gchar *) g_getenv ("XDG_DATA_DIRS");
 
       if (!data_dirs || !data_dirs[0])
-          data_dirs = "/usr/local/share/:/usr/share/";
+          data_dirs = "%%X11BASE%%/share/gnome/:/usr/local/share/gnome/:%%X11BASE%%/share/:/usr/local/share/:/usr/share/";
 
       data_dir_vector = g_strsplit (data_dirs, G_SEARCHPATH_SEPARATOR_S, 0);
 #endif
@@ -1983,7 +1983,7 @@ g_get_system_config_dirs (void)
       conf_dirs = (gchar *) g_getenv ("XDG_CONFIG_DIRS");
 
       if (!conf_dirs || !conf_dirs[0])
-          conf_dirs = "/etc/xdg";
+          conf_dirs = "%%X11BASE%%/etc/xdg:/usr/local/etc/xdg:/etc/xdg";
 
       conf_dir_vector = g_strsplit (conf_dirs, G_SEARCHPATH_SEPARATOR_S, 0);
 #endif
