--- src/dnd.c.orig	Mon Oct 25 16:50:41 2004
+++ src/dnd.c	Mon Oct 25 16:51:00 2004
@@ -7,6 +7,9 @@
 	GdkDragContext *context, gint x, gint y,
 	GtkSelectionData *selection_data, guint info, guint time)
 {
+	gchar *filename;
+	gchar *filename_real;
+	gchar *comline;
 	static gboolean flag_called_once = FALSE;
 	
 	if (flag_called_once) {
@@ -24,10 +27,6 @@
 	g_print("selection_data->data      = %s\n", selection_data->data);
 	g_print("selection_data->length    = %d\n", selection_data->length);
 });	
-	gchar *filename;
-	gchar *filename_real;
-	gchar *comline;
-	
 	if (selection_data->data && g_strstr_len(selection_data->data, 7, "file://")) {
 		filename = g_filename_from_uri(selection_data->data, NULL, NULL);
 		filename_real = g_strndup(filename, selection_data->length - 7 - 2);
