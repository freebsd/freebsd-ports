--- src/dh-base.c.orig	Tue May 15 13:00:24 2007
+++ src/dh-base.c	Sun Jul  8 03:48:13 2007
@@ -233,6 +233,10 @@ base_add_books_in_data_dir (DhBase *base
 	dir = g_build_filename (data_dir, "devhelp", "books", NULL);
 	base_add_books (base, dir);
 	g_free (dir);
+
+	dir = g_build_filename (data_dir, "doc", NULL);
+	base_add_books (base, dir);
+	g_free (dir);
 }
 
 static void
