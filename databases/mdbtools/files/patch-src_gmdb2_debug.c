--- src/gmdb2/debug.c.orig	Tue Apr 15 12:02:39 2003
+++ src/gmdb2/debug.c	Tue Apr 15 12:05:13 2003
@@ -354,6 +354,8 @@
 	GtkTextIter iter;
 	GtkTextView *textview;
 	GtkWidget *entry;
+	GtkWidget *tree;
+	GtkTreeView *store;
 	char pagestr[20];
 
 	textview = (GtkTextView *) glade_xml_get_widget (xml, "debug_textview");
@@ -395,8 +397,8 @@
 	gtk_text_buffer_get_iter_at_offset (buffer, &iter, 0);
 	gtk_text_buffer_insert(buffer,&iter,tbuf,strlen(tbuf));
 	
-	GtkWidget *tree = glade_xml_get_widget(xml, "debug_treeview");
-	GtkTreeView *store = (GtkTreeView *) gtk_tree_view_get_model(GTK_TREE_VIEW(tree));
+	tree = glade_xml_get_widget(xml, "debug_treeview");
+	store = (GtkTreeView *) gtk_tree_view_get_model(GTK_TREE_VIEW(tree));
 
 	gmdb_debug_dissect(GTK_TREE_STORE(store), fbuf, 0, length);
 
@@ -884,6 +886,11 @@
 guint32 page;
 GtkWidget *entry, *mi, *button, *debugwin;
 gchar text[20];
+GtkWidget *tree;
+GtkTreeStore *store;
+GtkCellRenderer *renderer;
+GtkTreeViewColumn *column;
+GtkTreeSelection *select;
 GladeXML *debugwin_xml;
 
 	/* load the interface */
@@ -947,11 +954,10 @@
 		pango_font_description_from_string("Courier"));
 			                			                
 	/* set up treeview, libglade only gives us the empty widget */
-	GtkWidget *tree = glade_xml_get_widget(debugwin_xml, "debug_treeview");
-	GtkTreeStore *store = gtk_tree_store_new(3, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT);
+	tree = glade_xml_get_widget(debugwin_xml, "debug_treeview");
+	store = gtk_tree_store_new(3, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT);
 	gtk_tree_view_set_model(GTK_TREE_VIEW(tree), GTK_TREE_MODEL(store));
 
-	GtkCellRenderer *renderer;
 	button = glade_xml_get_widget (debugwin_xml, "debug_button");
 	g_signal_connect (G_OBJECT (button), "clicked",
 		G_CALLBACK (gmdb_debug_display_cb), debugwin_xml);
@@ -960,13 +966,12 @@
 	gtk_signal_connect (GTK_OBJECT (debugwin), "delete_event",
 		GTK_SIGNAL_FUNC (gmdb_debug_delete_cb), debugwin_xml);
 
-	GtkTreeViewColumn *column;
 	renderer = gtk_cell_renderer_text_new();
 	column = gtk_tree_view_column_new_with_attributes("Field",
 		renderer, "text", 0, NULL);
 	gtk_tree_view_append_column(GTK_TREE_VIEW (tree), column);
 
-	GtkTreeSelection *select = 
+	select = 
 		gtk_tree_view_get_selection (GTK_TREE_VIEW (tree));
 	gtk_tree_selection_set_mode (select, GTK_SELECTION_SINGLE);
 	g_signal_connect (G_OBJECT (select), "changed",
