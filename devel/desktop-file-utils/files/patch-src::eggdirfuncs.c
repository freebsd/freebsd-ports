--- src/eggdirfuncs.c.orig	Thu Sep  2 15:44:39 2004
+++ src/eggdirfuncs.c	Tue Sep 21 01:24:07 2004
@@ -106,7 +106,7 @@
   data_dirs = (gchar *) g_getenv ("XDG_DATA_DIRS");
 
   if (!data_dirs || !data_dirs[0])
-    data_dirs = "/usr/local/share/:/usr/share/";
+    data_dirs = "%%X11BASE%%/share/:/usr/local/share/:/usr/share/:%%X11BASE%%/share/gnome/:/usr/local/share/gnome/:/usr/share/gnome/";
 
   data_dir_vector = g_strsplit (data_dirs, ":", 0);
 
