--- libgnomevfs/gnome-vfs-utils.c.orig	Thu Sep 15 07:02:53 2005
+++ libgnomevfs/gnome-vfs-utils.c	Sat Oct 22 02:12:32 2005
@@ -839,6 +839,7 @@ gnome_vfs_icon_path_from_filename (const
 	for (temp_paths = paths; *temp_paths != NULL; temp_paths++) {
 		full_filename = g_build_filename (*temp_paths,
 						  "share",
+						  "gnome",
 						  "pixmaps",
 						  relative_filename,
 						  NULL);
