--- gail/gailtreeview.c.orig	Tue Nov 22 19:01:37 2005
+++ gail/gailtreeview.c	Fri Nov 25 07:12:33 2005
@@ -678,7 +678,9 @@
 {
   GailTreeView *view = GAIL_TREE_VIEW (object);
 
-  /* remove anyg idle handlers still pending */
+  clear_cached_data (view);
+
+  /* remove any idle handlers still pending */
   if (view->idle_garbage_collect_id)
       g_source_remove (view->idle_garbage_collect_id);
 
@@ -692,8 +694,6 @@
   if (view->tree_model)
     disconnect_model_signals (view);
 
-  clear_cached_data (view);
-
   if (view->col_data)
     {
       GArray *array = view->col_data;
@@ -3295,8 +3295,10 @@
   GtkTreeIter new_iter;
   gboolean row_expanded;
 
-  if (increment == row)
+  if (increment == row) {
+    gtk_tree_path_free (current_path);
     return iter;
+  }
 
   row_expanded = gtk_tree_view_row_expanded (tree_view, current_path);
   gtk_tree_path_free (current_path);
@@ -3574,7 +3576,7 @@
 
       g_assert (GAIL_IS_TREE_VIEW (data));
       tree_view = (GailTreeView *)data;
-      temp_list = tree_view->cell_data;
+      temp_list = g_list_copy (tree_view->cell_data);
 
       tree_view->garbage_collection_pending = FALSE;
       tree_view->idle_garbage_collect_id = 0;
@@ -3586,14 +3588,15 @@
 	  if (!cell_info->in_use)
 	  {
 	      /* g_object_unref (cell_info->cell); */
-	      tree_view->cell_data = g_list_remove_link (tree_view->cell_data, 
-							 temp_list);
+	      tree_view->cell_data = g_list_remove (tree_view->cell_data, 
+						    cell_info);
 	      if (cell_info->cell_row_ref)
 		  gtk_tree_row_reference_free (cell_info->cell_row_ref);
 	      g_free (cell_info);
 	  }
           temp_list = temp_list->next;
       }
+      g_list_free (temp_list);
       
       return tree_view->garbage_collection_pending;
 }
@@ -3989,7 +3992,8 @@
       g_assert (GAIL_IS_TREE_VIEW (cell_info->view));
       if (!cell_info->view->garbage_collection_pending) {
 	  cell_info->view->garbage_collection_pending = TRUE;
-	  g_idle_add (garbage_collect_cell_data, cell_info->view);
+	  cell_info->view->idle_garbage_collect_id =
+	    g_idle_add (garbage_collect_cell_data, cell_info->view);
       }
   }
 }
