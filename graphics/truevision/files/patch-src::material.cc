--- src/material.cc.orig	Tue Jan  1 20:43:01 2002
+++ src/material.cc	Thu Jun 26 02:34:41 2003
@@ -66,7 +66,7 @@
 //**************************************
 // Add to list
 //**************************************
-void Material::add_to_list( GtkWidget *list, int position = -1 )
+void Material::add_to_list( GtkWidget *list, int position )
 {
 clist = GTK_CLIST( list );
 gchar *titre[] = { name->value() };
@@ -182,7 +182,7 @@
 item_type = ref.item_type;
 }
 
-void MaterialItem::add_to_tree( GtkCTree *tree, GtkCTreeNode *node , GtkCTreeNode *sibling = NULL )
+void MaterialItem::add_to_tree( GtkCTree *tree, GtkCTreeNode *node , GtkCTreeNode *sibling )
 {
 ctree = tree;
 parent_node = node;
