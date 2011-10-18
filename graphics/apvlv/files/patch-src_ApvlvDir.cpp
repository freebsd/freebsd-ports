--- src/ApvlvDir.cpp.orig	2011-06-24 11:30:12.000000000 +0400
+++ src/ApvlvDir.cpp	2011-10-11 22:07:59.000000000 +0400
@@ -49,7 +49,7 @@
   realname = NULL;
 
   GtkTreeIter nitr[1];
-  gtk_tree_store_append (dir->mStore, itr, ir);
+  gtk_tree_store_append (dir->mStore, nitr, ir);
   *itr = *nitr;
 
   GdkPixbuf *pix = gdk_pixbuf_new_from_file_at_size (iconreg.c_str (), 40,
