--- libgnomevfs/xdgmime.c.orig	Wed Aug 24 16:52:03 2005
+++ libgnomevfs/xdgmime.c	Wed Aug 24 16:52:47 2005
@@ -234,7 +234,7 @@
 
   xdg_data_dirs = getenv ("XDG_DATA_DIRS");
   if (xdg_data_dirs == NULL)
-    xdg_data_dirs = "/usr/local/share/:/usr/share/";
+    xdg_data_dirs = "%%LOCALBASE%%/share/";
 
   ptr = xdg_data_dirs;
 
