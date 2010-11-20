--- src/dh-book-manager.c.orig	2010-09-01 11:30:01.000000000 +0200
+++ src/dh-book-manager.c	2010-09-01 11:31:03.000000000 +0200
@@ -149,6 +149,10 @@ book_manager_add_books_in_data_dir (DhBo
         dir = g_build_filename (data_dir, "devhelp", "books", NULL);
         book_manager_add_from_dir (book_manager, dir);
         g_free (dir);
+
+        dir = g_build_filename (data_dir, "doc", NULL);
+        book_manager_add_from_dir (book_manager, dir);
+        g_free (dir);
 }
 
 void
