--- libgnomedb/gnome-db-find-dialog.c.orig	Thu Jul 22 17:40:26 2004
+++ libgnomedb/gnome-db-find-dialog.c	Thu Jul 22 17:41:02 2004
@@ -216,11 +216,12 @@
 GtkWidget *
 gnome_db_find_dialog_new_with_model (const gchar *title, GdaDataModel *dm)
 {
+	GnomeDbFindDialog *dialog;
 	g_return_val_if_fail (GDA_IS_DATA_MODEL (dm), NULL);
 	
 	g_object_ref (dm);
 	
-	GnomeDbFindDialog *dialog = gnome_db_find_dialog_new (title);
+	dialog = gnome_db_find_dialog_new (title);
 	gnome_db_find_dialog_add_fields_from_model (dialog, dm);
 
 	g_object_unref (dm);
