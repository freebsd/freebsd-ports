--- src/dh-base.c.orig	2008-10-11 00:00:18.000000000 +0200
+++ src/dh-base.c	2009-01-09 23:10:12.000000000 +0100
@@ -214,6 +214,11 @@ base_add_books_in_data_dir (DhBase      
         dir = g_build_filename (data_dir, "devhelp", "books", NULL);
         base_add_books (base, dir);
         g_free (dir);
+
+        dir = g_build_filename (data_dir, "doc", NULL);
+        base_add_books (base, dir);
+        g_free (dir);
+
 }
 
 static void
