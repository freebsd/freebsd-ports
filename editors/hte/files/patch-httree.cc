$FreeBSD$

--- httree.cc.orig	Fri Jun  7 22:23:41 2002
+++ httree.cc	Fri Jun  7 22:24:02 2002
@@ -380,7 +380,7 @@
 	ht_treeview::done();
 }
 
-void *ht_static_treeview::add_child(void *node, char *text, ht_data *Data=NULL)
+void *ht_static_treeview::add_child(void *node, char *text, ht_data *Data)
 {
 	if (node) {
 		return add_node(&((static_node *)node)->child, text, Data);
@@ -394,7 +394,7 @@
 	}
 }
 
-void	*ht_static_treeview::add_node(static_node **node, char *text, ht_data *Data=NULL)
+void	*ht_static_treeview::add_node(static_node **node, char *text, ht_data *Data)
 {
 	static_node **p = node;
 	static_node *prev = NULL;
@@ -413,7 +413,7 @@
 	((static_node *)node)->expanded = expand;
 }
 
-static_node *ht_static_treeview::create_node(char *text, static_node *prev, ht_data *Data=NULL)
+static_node *ht_static_treeview::create_node(char *text, static_node *prev, ht_data *Data)
 {
 	static_node *node = (static_node *)malloc(sizeof(static_node));
 	node->text = ht_strdup(text);
