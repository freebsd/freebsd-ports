--- src/mlview-icon-tree.c.orig	Thu Nov 20 21:07:14 2003
+++ src/mlview-icon-tree.c	Sat Dec  6 20:52:53 2003
@@ -388,9 +388,11 @@
         guchar *result = NULL,
                 *content = NULL;
   
+        const gchar *colour_str;
+
         g_return_val_if_fail (a_node != NULL, NULL);
   
-        const gchar *colour_str = mlview_tree_editor2_get_colour_string (a_node->type);
+        colour_str = mlview_tree_editor2_get_colour_string (a_node->type);
   
         if (a_node->type == XML_ELEMENT_NODE) {
                 guchar *ns_prefix = NULL,
