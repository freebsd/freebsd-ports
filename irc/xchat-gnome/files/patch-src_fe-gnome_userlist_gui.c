--- src/fe-gnome/userlist_gui.c.orig	Wed Sep  1 14:19:24 2004
+++ src/fe-gnome/userlist_gui.c	Wed Sep  1 14:21:39 2004
@@ -52,6 +52,22 @@
 	g_signal_connect(G_OBJECT(userlist_view), "button_press_event", G_CALLBACK(userlist_click), NULL);
 }
 
+struct User *userlist_get_selected() {
+	GtkWidget *treeview;
+	GtkTreeSelection *select;
+	GtkTreeModel *model;
+	GtkTreeIter iter;
+	struct User *u;
+
+	treeview = glade_xml_get_widget(gui.xml, "userlist");
+	select = gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview));
+	if(gtk_tree_selection_get_selected(select, &model, &iter)) {
+		gtk_tree_model_get(model, &iter, 2, &u, -1);
+		return u;
+	}
+	return NULL;
+}
+
 gboolean userlist_click(GtkWidget *view, GdkEventButton *event, gpointer data) {
 	GtkTreePath *path;
 	GtkTreeSelection *select;
@@ -77,22 +93,6 @@
 		return TRUE;
 	}
 	return FALSE;
-}
-
-struct User *userlist_get_selected() {
-	GtkWidget *treeview;
-	GtkTreeSelection *select;
-	GtkTreeModel *model;
-	GtkTreeIter iter;
-	struct User *u;
-
-	treeview = glade_xml_get_widget(gui.xml, "userlist");
-	select = gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview));
-	if(gtk_tree_selection_get_selected(select, &model, &iter)) {
-		gtk_tree_model_get(model, &iter, 2, &u, -1);
-		return u;
-	}
-	return NULL;
 }
 
 void userlist_context(GtkWidget *treeview, struct User *user) {
