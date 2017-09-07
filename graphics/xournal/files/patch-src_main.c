--- src/main.c.orig	2015-10-25 04:26:29 UTC
+++ src/main.c
@@ -360,7 +360,7 @@ main (int argc, char *argv[])
   g_free(path);
   g_free(path1);
   g_free(path2);
-  add_pixmap_directory (PACKAGE_DATA_DIR "/" PACKAGE "/pixmaps");
+  add_pixmap_directory (PACKAGE_DATA_DIR);
 
   /*
    * The following code was added by Glade to create one of each component
