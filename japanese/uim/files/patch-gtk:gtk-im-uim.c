--- gtk/gtk-im-uim.c.orig	Sat Jun 26 22:53:23 2004
+++ gtk/gtk-im-uim.c	Sat Jun 26 22:53:39 2004
@@ -807,14 +807,14 @@
 
   while(column_list) {
     gint width,height;
+    GtkWidget *widget = gtk_tree_view_column_get_widget(GTK_TREE_VIEW_COLUMN(column_list->data));
+    GtkRequisition req_column;
+
     gtk_tree_view_column_cell_get_size (GTK_TREE_VIEW_COLUMN(column_list->data),
 				    NULL,
 				    NULL, NULL,
 				    &width,
 				    &height);
-
-    GtkWidget *widget = gtk_tree_view_column_get_widget(GTK_TREE_VIEW_COLUMN(column_list->data));
-    GtkRequisition req_column;
 
     if(!widget) {
       column_list = g_list_next(column_list);
