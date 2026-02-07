--- src/rs-tag-gui.c.orig	2011-02-15 17:28:05 UTC
+++ src/rs-tag-gui.c
@@ -93,11 +93,6 @@ rs_tag_gui_toolbox_new(RSLibrary *library, RSStore *st
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
@@ -178,6 +173,11 @@ rs_library_tag_entry_new(RSLibrary *library)
 
 		return found;
 	}
+
+GtkWidget *
+rs_library_tag_entry_new(RSLibrary *library)
+{
+	g_assert(RS_IS_LIBRARY(library));
 
 	GtkWidget *entry = gtk_entry_new();
 	GtkEntryCompletion *completion = gtk_entry_completion_new();
