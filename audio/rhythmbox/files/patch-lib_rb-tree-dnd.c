--- lib/rb-tree-dnd.c.orig	Tue Nov 11 20:58:54 2003
+++ lib/rb-tree-dnd.c	Tue Nov 11 20:59:17 2003
@@ -710,9 +710,10 @@
 				 gint n_targets,
 				 GdkDragAction actions)
 {
+    	RbTreeDndData *priv_data;
  	g_return_if_fail (GTK_IS_TREE_VIEW (tree_view));
 
-	RbTreeDndData *priv_data = init_rb_tree_dnd_data (GTK_WIDGET(tree_view));
+	priv_data = init_rb_tree_dnd_data (GTK_WIDGET(tree_view));
 
 	if (!priv_data->button_press_event_handler) {
 
@@ -746,9 +747,10 @@
 			       gint n_targets,
 			       GdkDragAction actions)
 {
+    	RbTreeDndData *priv_data;
 	g_return_if_fail (GTK_IS_TREE_VIEW (tree_view));
 
-	RbTreeDndData *priv_data = init_rb_tree_dnd_data (GTK_WIDGET(tree_view));
+	priv_data = init_rb_tree_dnd_data (GTK_WIDGET(tree_view));
 
 	if (!priv_data->drag_leave_handler) {
 
