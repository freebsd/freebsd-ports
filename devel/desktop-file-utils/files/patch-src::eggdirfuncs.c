--- src/eggdirfuncs.c.orig	Sat Jul 24 01:53:05 2004
+++ src/eggdirfuncs.c	Sat Jul 24 01:53:31 2004
@@ -106,7 +106,7 @@
   data_dirs = (gchar *) g_getenv ("XDG_DATA_DIRS");
 
   if (!data_dirs || !data_dirs[0])
-    data_dirs = (char *) "/usr/local/share/:/usr/share/";
+    data_dirs = (char *) "/usr/local/share/:%%X11BASE%%/share/:/usr/share/:/usr/local/share/gnome/:%%X11BASE%%/share/gnome/:/usr/share/gnome/";
 
   data_dir_vector = g_strsplit (data_dirs, ":", 0);
 
