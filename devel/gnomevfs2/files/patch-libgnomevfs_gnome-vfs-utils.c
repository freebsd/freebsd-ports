--- libgnomevfs/gnome-vfs-utils.c.orig	Fri Apr 25 06:52:18 2003
+++ libgnomevfs/gnome-vfs-utils.c	Tue May  6 15:44:27 2003
@@ -42,6 +42,7 @@
 #include <pwd.h>
 #include <stdlib.h>
 #include <string.h>
+#include <sys/param.h>
 #include <sys/stat.h>
 #include <sys/types.h>
 #include <unistd.h>
@@ -840,7 +841,7 @@
 	paths = g_strsplit (gnome_var, ":", 0); 
 
 	for (temp_paths = paths; *temp_paths != NULL; temp_paths++) {
-		full_filename = g_strconcat (*temp_paths, "/share/pixmaps/", relative_filename, NULL);
+		full_filename = g_strconcat (*temp_paths, "/share/gnome/pixmaps/", relative_filename, NULL);
 		if (g_file_test (full_filename, G_FILE_TEST_EXISTS)) {
 			g_strfreev (paths);
 			return full_filename;
