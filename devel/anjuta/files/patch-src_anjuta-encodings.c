--- src/anjuta-encodings.c.orig	2005-12-15 18:50:55.000000000 +0100
+++ src/anjuta-encodings.c	2005-12-15 18:51:38.000000000 +0100
@@ -707,15 +707,15 @@
 	gtk_tree_view_set_search_column (GTK_TREE_VIEW (stock_treeview),
 									 COLUMN_ENCODING_NAME);
 	selection = gtk_tree_view_get_selection (GTK_TREE_VIEW (stock_treeview));
 	g_return_if_fail (selection != NULL);
 	gtk_tree_selection_set_mode (selection, GTK_SELECTION_MULTIPLE);
-	g_signal_connect (G_OBJECT (selection), "changed",
-					  G_CALLBACK (on_stock_selection_changed), NULL);
 
 	model = create_encodings_treeview_model ();
 	gtk_tree_view_set_model (GTK_TREE_VIEW (stock_treeview), model);
+	g_signal_connect (G_OBJECT (selection), "changed",
+					  G_CALLBACK (on_stock_selection_changed), NULL);
 	g_object_unref (model);
 
 	/* Add the encoding column for supported treeview*/
 	cell = gtk_cell_renderer_text_new ();
 	column = gtk_tree_view_column_new_with_attributes (_("Supported Encodings"),
@@ -726,17 +726,17 @@
 	gtk_tree_view_set_search_column (GTK_TREE_VIEW (supported_treeview),
 									 COLUMN_ENCODING_NAME);
 	selection = gtk_tree_view_get_selection (GTK_TREE_VIEW (supported_treeview));
 	g_return_if_fail (selection != NULL);
 	gtk_tree_selection_set_mode (selection, GTK_SELECTION_BROWSE);
-	g_signal_connect (G_OBJECT (selection), "changed",
-					  G_CALLBACK (on_supported_selection_changed), NULL);
 
 	/* create list store */
 	model = GTK_TREE_MODEL (gtk_list_store_new (SUPPORTED_ENCODING_NUM_COLS,
 												G_TYPE_STRING, G_TYPE_POINTER));
 	gtk_tree_view_set_model (GTK_TREE_VIEW (supported_treeview), model);
+	g_signal_connect (G_OBJECT (selection), "changed",
+					  G_CALLBACK (on_supported_selection_changed), NULL);
 	g_object_unref (model);
 	
 	anjuta_preferences_register_property_custom (pref, supported_treeview,
 												SUPPORTED_ENCODINGS,
 												"ISO-8859-15",
