--- src/dh-base.c.orig	Tue Jun  3 12:21:34 2003
+++ src/dh-base.c	Tue Jun  3 12:23:04 2003
@@ -155,6 +155,7 @@
 	
 	/* Insert the books from default gtk-doc install path */
 	base_add_books (base, DATADIR"/gtk-doc/html");
+	base_add_books (base, DATADIR"/../doc"); // FreeBSD default doc path
 	base_add_books (base, "/usr/share/gtk-doc/html");
 	base_add_books (base, DATADIR"/devhelp/books");
 	dir = g_strconcat (g_getenv ("HOME"), "/.devhelp/books", NULL);
