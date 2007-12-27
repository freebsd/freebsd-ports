--- src/websearch.c.orig	2007-12-28 00:10:21.000000000 +0900
+++ src/websearch.c	2007-12-28 00:28:26.000000000 +0900
@@ -33,7 +33,6 @@
 void web_search();
 void split_word(gchar *word, gchar **keywords);
 
-static GtkWidget *web_tree;
 static GtkCTreeNode *current_node;
 static GtkItemFactory *tree_item_factory;
 static GtkItemFactoryEntry tree_menu_items[] = {
