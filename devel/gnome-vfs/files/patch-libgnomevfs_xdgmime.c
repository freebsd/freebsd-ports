--- libgnomevfs/xdgmime.c.orig	Thu Jul 22 11:20:13 2004
+++ libgnomevfs/xdgmime.c	Thu Jul 22 11:20:52 2004
@@ -189,7 +189,7 @@
 
   xdg_data_dirs = getenv ("XDG_DATA_DIRS");
   if (xdg_data_dirs == NULL)
-    xdg_data_dirs = "/usr/local/share/:/usr/share/";
+    xdg_data_dirs = "%%X11BASE%%/share/gnome/:/usr/local/share/gnome/:%%X11BASE%%/share/:/usr/local/share/:/usr/share/";
 
   ptr = xdg_data_dirs;
 
