--- src/update-desktop-database.c.orig	Fri Aug  6 17:36:29 2004
+++ src/update-desktop-database.c	Fri Aug  6 17:35:41 2004
@@ -381,7 +381,7 @@
 
   for (i = 0; data_dirs[i] != NULL; i++);
 
-  args = g_new (char *, i + 1);
+  args = g_new0 (char *, i + 1);
 
   for (i = 0; data_dirs[i] != NULL; i++)
     args[i] = g_build_filename (data_dirs[i], "applications", NULL);
