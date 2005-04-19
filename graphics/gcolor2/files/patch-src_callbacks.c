--- src/callbacks.c.orig	Tue Apr 19 00:37:37 2005
+++ src/callbacks.c	Tue Apr 19 00:39:22 2005
@@ -126,8 +126,9 @@
 	
 	if (gtk_tree_selection_get_selected (selection, &model, &selection_iter))
 	{
+	  	GtkColorSelection *colorsel;
 		gtk_tree_model_get (model, &selection_iter, COLOR_VALUE, &color, COLOR_TYPE, &type, -1);
-		GtkColorSelection *colorsel = GTK_COLOR_SELECTION (lookup_widget (gcolor2, "colorselection1"));
+		colorsel = GTK_COLOR_SELECTION (lookup_widget (gcolor2, "colorselection1"));
 		gdk_color_parse (color, &new_color);
 		
 		/* save the old color */
@@ -249,9 +250,10 @@
 on_save_button_clicked                 (GtkButton       *button,
                                         gpointer         user_data)
 {
+	gint result;
 	savedialog = create_save_dialog ();
 	gtk_window_set_transient_for (GTK_WINDOW (savedialog), GTK_WINDOW (gcolor2));
-	gint result = gtk_dialog_run (GTK_DIALOG (savedialog));
+	result = gtk_dialog_run (GTK_DIALOG (savedialog));
 	switch (result)
 	{
 		case GTK_RESPONSE_OK:
@@ -269,18 +271,19 @@
 save_selected_color                    ()
 {
 	GtkWidget *entry = lookup_widget (savedialog, "entry1");
+	GtkTreeView *list;
+	FILE *fp;
+	gint r, g, b;
+	gchar old[512] = "";
 	colorname = g_strdup (gtk_entry_get_text (GTK_ENTRY (entry)));
 	add_list_color (colorvalue, colorname, "user", TRUE);
 	
-	GtkTreeView *list = GTK_TREE_VIEW (lookup_widget (gcolor2, "treeview1"));
+	list = GTK_TREE_VIEW (lookup_widget (gcolor2, "treeview1"));
 	gtk_tree_view_scroll_to_cell (list, gtk_tree_path_new_first (), NULL, FALSE, 0, 0);
 	gtk_tree_selection_select_path  (gtk_tree_view_get_selection (list), gtk_tree_path_new_first ());
 	
 	
 	/* save color in user file - write at top of the file */
-	FILE *fp;
-	gint r, g, b;
-	gchar old[512] = "";
 
 	sscanf (colorvalue, "#%2x%2x%2x", &r, &g, &b);
 	fp = fopen (get_filename (), "r");
@@ -307,8 +310,9 @@
                                         gpointer         user_data)
 {
 	GtkWidget *deletedialog = create_delete_dialog ();
+	gint result;
 	gtk_window_set_transient_for (GTK_WINDOW (deletedialog), GTK_WINDOW (gcolor2));
-	gint result = gtk_dialog_run (GTK_DIALOG (deletedialog));
+	result = gtk_dialog_run (GTK_DIALOG (deletedialog));
 	switch (result)
 	{
 		case GTK_RESPONSE_OK:
@@ -330,15 +334,22 @@
 	
 	gchar *selection_color_name;
 	gchar *selection_color_value;
-	gtk_tree_model_get (model, &selection_iter, COLOR_VALUE, &selection_color_value, COLOR_NAME, &selection_color_name, -1);
-	
-	
-	/* remove from file */
+
 	FILE *fp;
 	gchar *p;
 	gchar buffer[512] = "";
 	gchar newstuff[512] = "";
 
+	gint r, g, b;
+	gchar *file_color_name;
+	gchar file_color_value[8];
+	gboolean found = FALSE;
+
+	gtk_tree_model_get (model, &selection_iter, COLOR_VALUE, &selection_color_value, COLOR_NAME, &selection_color_name, -1);
+	
+	
+	/* remove from file */
+
 	fp = fopen (get_filename (), "r");
 	if (fp == NULL)
 	{
@@ -346,10 +357,6 @@
 		return;
 	}
 
-	gint r, g, b;
-	gchar *file_color_name;
-	gchar file_color_value[8];
-	gboolean found = FALSE;
 	while ((p = fgets (buffer, sizeof buffer, fp)) != NULL)
 	{
 		if (buffer[0] == '!')
