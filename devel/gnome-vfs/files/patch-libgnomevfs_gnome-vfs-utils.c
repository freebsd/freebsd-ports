--- libgnomevfs/gnome-vfs-utils.c.orig	Sun May  5 17:01:22 2002
+++ libgnomevfs/gnome-vfs-utils.c	Sun May  5 17:02:24 2002
@@ -774,7 +774,7 @@
 	paths = g_strsplit (gnome_var, ":", 0); 
 
 	for (temp_paths = paths; *temp_paths != NULL; temp_paths++) {
-		full_filename = g_strconcat (*temp_paths, "/share/pixmaps/", relative_filename, NULL);
+		full_filename = g_strconcat (*temp_paths, "/share/gnome/pixmaps/", relative_filename, NULL);
 		if (hack_file_exists (full_filename)) {
 			g_strfreev (paths);
 			return full_filename;
