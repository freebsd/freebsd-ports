--- src/mlview-ns-editor.c.orig	Thu Nov 13 01:06:36 2003
+++ src/mlview-ns-editor.c	Sat Dec  6 20:51:10 2003
@@ -1063,12 +1063,6 @@
                             xmlNode *a_node,
                             xmlNs *a_ns)
 {
-        g_return_val_if_fail (a_this 
-                              && MLVIEW_IS_NS_EDITOR (a_this)
-                              && a_node
-                              && a_ns,
-                              MLVIEW_BAD_PARAM_ERROR) ;
-
         GtkTreeRowReference *row_ref = NULL ;
         GtkTreePath *tree_path = NULL ;
         GtkTreeIter iter = {0} ;
@@ -1076,6 +1070,12 @@
         gboolean is_ok = FALSE ;
         xmlNs *ns = NULL ;
         enum MlViewStatus status = MLVIEW_OK ;
+
+        g_return_val_if_fail (a_this 
+                              && MLVIEW_IS_NS_EDITOR (a_this)
+                              && a_node
+                              && a_ns,
+                              MLVIEW_BAD_PARAM_ERROR) ;
 
         if (PRIVATE (a_this)->cur_xml_node != a_node) {
                 return MLVIEW_OK ;                
