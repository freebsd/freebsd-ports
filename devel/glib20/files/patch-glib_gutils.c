--- glib/gutils.c.orig	Sat Sep  4 15:49:27 2004
+++ glib/gutils.c	Sat Sep  4 15:55:24 2004
@@ -1466,7 +1466,7 @@
       data_dirs = (gchar *) g_getenv ("XDG_DATA_DIRS");
 
       if (!data_dirs || !data_dirs[0])
-          data_dirs = "/usr/local/share/:/usr/share/";
+          data_dirs = "%%X11BASE%%/share/gnome/:/usr/local/share/gnome/:%%X11BASE%%/share/:/usr/local/share/:/usr/share/";
 #endif
       data_dir_vector = g_strsplit (data_dirs, G_SEARCHPATH_SEPARATOR_S, 0);
 
@@ -1509,7 +1509,7 @@
       conf_dirs = (gchar *) g_getenv ("XDG_CONFIG_DIRS");
 
       if (!conf_dirs || !conf_dirs[0])
-          conf_dirs = "/etc/xdg";
+          conf_dirs = "%%X11BASE%%/etc/xdg:/usr/local/etc/xdg:/etc/xdg";
 #endif
       conf_dir_vector = g_strsplit (conf_dirs, G_SEARCHPATH_SEPARATOR_S, 0);
     }
