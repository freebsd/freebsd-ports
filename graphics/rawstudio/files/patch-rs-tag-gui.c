--- src/rs-tag-gui.c.orig	2011-02-15 18:28:05.000000000 +0100
+++ src/rs-tag-gui.c	2014-02-14 18:36:48.000000000 +0100
@@ -93,11 +93,6 @@
 	return box;
 }
 
-GtkWidget *
-rs_library_tag_entry_new(RSLibrary *library)
-{
-	g_assert(RS_IS_LIBRARY(library));
-
 	gboolean
 	selected(GtkEntryCompletion *completion, GtkTreeModel *model, GtkTreeIter *iter, gpointer user_data)
 	{
@@ -179,6 +174,11 @@
 		return found;
 	}
 
+GtkWidget *
+rs_library_tag_entry_new(RSLibrary *library)
+{
+	g_assert(RS_IS_LIBRARY(library));
+
 	GtkWidget *entry = gtk_entry_new();
 	GtkEntryCompletion *completion = gtk_entry_completion_new();
 	GtkListStore *store = gtk_list_store_new(1, G_TYPE_STRING);
