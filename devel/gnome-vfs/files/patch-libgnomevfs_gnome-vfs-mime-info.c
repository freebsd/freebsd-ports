--- libgnomevfs/gnome-vfs-mime-info.c.orig	Wed Aug  4 13:41:52 2004
+++ libgnomevfs/gnome-vfs-mime-info.c	Wed Aug  4 13:42:10 2004
@@ -149,7 +149,7 @@
 
 	xdg_data_dirs = g_getenv ("XDG_DATA_DIRS");
 	if (!xdg_data_dirs) {
-		xdg_data_dirs = "/usr/local/share/:/usr/share/";
+		xdg_data_dirs = "%%X11BASE%%/share/gnome/:/usr/local/share/gnome/:%%X11BASE%%/share/:/usr/local/share/:/usr/share/";
 	}
 	
 	split_data_dirs = g_strsplit (xdg_data_dirs, ":", 0);
