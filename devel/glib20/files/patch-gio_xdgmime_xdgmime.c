--- gio/xdgmime/xdgmime.c.orig	Mon Nov  8 22:25:27 2004
+++ gio/xdgmime/xdgmime.c	Sat Nov 13 10:27:22 2004
@@ -204,7 +204,7 @@
 
   xdg_data_dirs = getenv ("XDG_DATA_DIRS");
   if (xdg_data_dirs == NULL)
-    xdg_data_dirs = "/usr/local/share/:/usr/share/";
+    xdg_data_dirs = "/usr/local/share/";
 
   ptr = xdg_data_dirs;
 
