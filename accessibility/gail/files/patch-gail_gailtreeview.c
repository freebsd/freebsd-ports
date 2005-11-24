--- gail/gailtreeview.c.orig	Thu Oct  6 13:17:11 2005
+++ gail/gailtreeview.c	Thu Nov 24 05:45:24 2005
@@ -2249,7 +2249,7 @@
   gint n_inserted, row;
 
   tree_model = gtk_tree_view_get_model(tree_view);
-  if (!gtk_tree_model_get_iter (tree_model, &iter, path))
+  if (!path || !gtk_tree_model_get_iter (tree_model, &iter, path))
       return FALSE;
 
   /*
@@ -2294,8 +2294,8 @@
   
   g_signal_emit_by_name (gailview, "row_inserted", row, n_inserted);
 
+  gailview->idle_expand_path = NULL;
   gtk_tree_path_free (path);
-  g_free (data);
   return FALSE;
 }
 
