--- src/gmdb2/sql.c.orig	Tue Apr 15 12:05:45 2003
+++ src/gmdb2/sql.c	Tue Apr 15 12:07:32 2003
@@ -375,6 +375,7 @@
 GType *gtypes;
 GtkTreeIter iter;
 GtkTreeViewColumn *column;
+GtkCellRenderer *renderer;
 long row, maxrow;
 
 	/* stuff this query on the history */
@@ -422,7 +423,6 @@
 
 	gtk_tree_view_set_model(GTK_TREE_VIEW(treeview), GTK_TREE_MODEL(store));
 	
-	GtkCellRenderer *renderer;
 	renderer = gtk_cell_renderer_text_new(); 
 
 	for (i=0;i<sql->num_columns;i++) { 
@@ -464,6 +464,12 @@
 	GtkWidget *mi, *but, *combo;
 	GladeXML *sqlwin_xml;
 	GValue value = {0, };
+	GtkWidget *tree;
+	GtkTreeStore *store;
+	GtkCellRenderer *renderer;
+	GtkTreeViewColumn *column;
+	GtkTreeSelection *select;
+	GtkWidget *textview;
 
 	/* load the interface */
 	sqlwin_xml = glade_xml_new(GMDB_GLADEDIR "gmdb-sql.glade", NULL, NULL);
@@ -537,18 +543,16 @@
 		G_CALLBACK (gmdb_sql_execute_cb), sqlwin_xml);
 
 	/* set up treeview, libglade only gives us the empty widget */
-	GtkWidget *tree = glade_xml_get_widget(sqlwin_xml, "sql_treeview");
-	GtkTreeStore *store = gtk_tree_store_new(1, G_TYPE_STRING);
+	tree = glade_xml_get_widget(sqlwin_xml, "sql_treeview");
+	store = gtk_tree_store_new(1, G_TYPE_STRING);
 	gtk_tree_view_set_model(GTK_TREE_VIEW(tree), GTK_TREE_MODEL(store));
 
-	GtkCellRenderer *renderer;
-	GtkTreeViewColumn *column;
 	renderer = gtk_cell_renderer_text_new();
 	column = gtk_tree_view_column_new_with_attributes("Name",
 		renderer, "text", 0, NULL);
 	gtk_tree_view_append_column(GTK_TREE_VIEW (tree), column);
 
-	GtkTreeSelection *select = 
+	select = 
 		gtk_tree_view_get_selection (GTK_TREE_VIEW (tree));
 	gtk_tree_selection_set_mode (select, GTK_SELECTION_SINGLE);
 	//g_signal_connect (G_OBJECT (select), "changed",
@@ -557,7 +561,7 @@
 	/* populate first level of tree */
 	gmdb_sql_tree_populate(mdb, sqlwin_xml);
 
-	GtkWidget *textview = glade_xml_get_widget(sqlwin_xml, "sql_textview");
+	textview = glade_xml_get_widget(sqlwin_xml, "sql_textview");
 	src.target = "table";
 	src.flags = 0;
 	src.info = 1;
