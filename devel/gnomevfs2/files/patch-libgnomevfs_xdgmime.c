--- libgnomevfs/xdgmime.c.orig	Wed Jun 23 20:15:25 2004
+++ libgnomevfs/xdgmime.c	Wed Jun 23 20:15:41 2004
@@ -97,7 +97,7 @@
 
       xdg_data_dirs = getenv ("XDG_DATA_DIRS");
       if (xdg_data_dirs == NULL)
-	xdg_data_dirs = "/usr/local/share/:/usr/share/";
+	xdg_data_dirs = "%%X11BASE%%/share/gnome/:/usr/local/share/gnome/:%%X11BASE%%/share/:/usr/local/share/:/usr/share/";
 
       ptr = xdg_data_dirs;
 
