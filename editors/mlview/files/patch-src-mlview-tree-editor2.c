--- src/mlview-tree-editor2.c.orig	Thu Nov 20 09:11:34 2003
+++ src/mlview-tree-editor2.c	Sat Dec  6 20:48:30 2003
@@ -760,9 +760,11 @@
         guchar *result = NULL,
                 *content = NULL;
 
+        const gchar *colour_str;
+	
         g_return_val_if_fail (a_node != NULL, NULL);
 
-        const gchar *colour_str = mlview_tree_editor2_get_colour_string (a_node->type);
+        colour_str = mlview_tree_editor2_get_colour_string (a_node->type);
 
         if (a_node->type == XML_ELEMENT_NODE) {
                 guchar *ns_prefix = NULL,
