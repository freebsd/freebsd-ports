--- libgnomevfs/gnome-vfs-utils.c.orig	Fri Dec 20 16:15:06 2002
+++ libgnomevfs/gnome-vfs-utils.c	Tue Jan 14 00:54:10 2003
@@ -40,6 +40,7 @@
 #include <pwd.h>
 #include <stdlib.h>
 #include <string.h>
+#include <sys/param.h>
 #include <sys/stat.h>
 #include <sys/types.h>
 #include <unistd.h>
@@ -861,7 +862,7 @@
 	paths = g_strsplit (gnome_var, ":", 0); 
 
 	for (temp_paths = paths; *temp_paths != NULL; temp_paths++) {
-		full_filename = g_strconcat (*temp_paths, "/share/pixmaps/", relative_filename, NULL);
+		full_filename = g_strconcat (*temp_paths, "/share/gnome/pixmaps/", relative_filename, NULL);
 		if (hack_file_exists (full_filename)) {
 			g_strfreev (paths);
 			return full_filename;
