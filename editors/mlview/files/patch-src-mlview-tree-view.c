--- src/mlview-tree-view.c.orig	Sat May  1 23:36:40 2004
+++ src/mlview-tree-view.c	Wed Jul 28 15:25:16 2004
@@ -746,11 +746,11 @@
 mlview_tree_view_build_contextual_menu (MlViewTreeView *a_this)
 {
         struct TreeEditorContextualMenuHandle *menu_handle = NULL ;
+        GtkWidget *menu = NULL, *menuitem = NULL, *submenu = NULL;
         
         g_return_val_if_fail (a_this
                               && MLVIEW_IS_TREE_VIEW (a_this),
                               MLVIEW_BAD_PARAM_ERROR) ;
-        GtkWidget *menu = NULL, *menuitem = NULL, *submenu = NULL;
 
         menu_handle = g_try_malloc
                 (sizeof (struct TreeEditorContextualMenuHandle)) ;
