--- src/dh-base.c.orig	Sat Jun 28 22:16:34 2003
+++ src/dh-base.c	Sun Jun 29 13:40:23 2003
@@ -222,6 +222,7 @@
 	
 	/* Insert the books from default gtk-doc install path. */
 	base_add_books (base, DATADIR "/gtk-doc/html");
+	base_add_books (base, DATADIR "/../doc"); // FreeBSD default doc path
 	base_add_books (base, "/usr/share/gtk-doc/html");
 	base_add_books (base, DATADIR "/devhelp/books");
 	dir = g_build_filename (g_get_home_dir (), ".devhelp", "books", NULL);
