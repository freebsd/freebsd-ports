--- lib/gtk2/gtk/gtkctree.c.orig	Sun Oct  8 23:15:57 2006
+++ lib/gtk2/gtk/gtkctree.c	Sun Oct  8 23:18:58 2006
@@ -563,24 +563,12 @@ gtk_ctree_set_arg (GtkObject      *objec
   switch (arg_id)
     {
     case ARG_N_COLUMNS: /* construct-only arg, only set at construction time */
-      g_return_if_fail (clist->row_mem_chunk == NULL);
       clist->columns = MAX (1, GTK_VALUE_UINT (*arg));
-      clist->row_mem_chunk = g_mem_chunk_new ("ctree row mem chunk",
-					      sizeof (GtkCTreeRow),
-					      sizeof (GtkCTreeRow)
-					      * CLIST_OPTIMUM_SIZE,
-					      G_ALLOC_AND_FREE);
-      clist->cell_mem_chunk = g_mem_chunk_new ("ctree cell mem chunk",
-					       sizeof (GtkCell) * clist->columns,
-					       sizeof (GtkCell) * clist->columns
-					       * CLIST_OPTIMUM_SIZE,
-					       G_ALLOC_AND_FREE);
       ctree->tree_column = CLAMP (ctree->tree_column, 0, clist->columns);
       break;
     case ARG_TREE_COLUMN: /* construct-only arg, only set at construction time */
       ctree->tree_column = GTK_VALUE_UINT (*arg);
-      if (clist->row_mem_chunk)
-	ctree->tree_column = CLAMP (ctree->tree_column, 0, clist->columns);
+      ctree->tree_column = CLAMP (ctree->tree_column, 0, clist->columns);
       break;
     case ARG_INDENT:
       gtk_ctree_set_indent (ctree, GTK_VALUE_UINT (*arg));
@@ -3197,8 +3185,8 @@ row_new (GtkCTree *ctree)
   int i;
 
   clist = GTK_CLIST (ctree);
-  ctree_row = g_chunk_new (GtkCTreeRow, clist->row_mem_chunk);
-  ctree_row->row.cell = g_chunk_new (GtkCell, clist->cell_mem_chunk);
+  ctree_row = g_slice_new (GtkCTreeRow);
+  ctree_row->row.cell = g_slice_alloc (sizeof (GtkCell) * clist->columns);
 
   for (i = 0; i < clist->columns; i++)
     {
@@ -3286,8 +3274,8 @@ row_delete (GtkCTree    *ctree,
       dnotify (ddata);
     }
 
-  g_mem_chunk_free (clist->cell_mem_chunk, ctree_row->row.cell);
-  g_mem_chunk_free (clist->row_mem_chunk, ctree_row);
+  g_slice_free1 (sizeof (GtkCell) * clist->columns, ctree_row->row.cell);
+  g_slice_free (GtkCTreeRow, ctree_row);
 }
 
 static void
