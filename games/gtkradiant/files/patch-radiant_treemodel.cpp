--- radiant/treemodel.cpp.orig	2006-02-10 22:01:20 UTC
+++ radiant/treemodel.cpp
@@ -1243,7 +1243,13 @@ const char* node_get_name(scene::Node& n
 
 const char* node_get_name_safe(scene::Node& node)
 {
-  if(&node == 0)
+  // Reference cannot be bound to dereferenced null pointer in well-defined
+  // C++ code, and Clang will assume that comparison below always evaluates
+  // to false, resulting in segmentation fault.  Use a dirty hack to insist
+  // that Clang checks it for null.
+  volatile int n = (int)&node;
+
+  if(n == 0)
   {
     return "";
   }
@@ -1264,7 +1270,9 @@ GraphTreeNode* graph_tree_model_find_par
 
 void node_attach_name_changed_callback(scene::Node& node, const NameCallback& callback)
 {
-  if(&node != 0)
+  volatile int n = (int)&node;		// see the comment on line 1246
+
+  if(n != 0)
   {
     Nameable* nameable = Node_getNameable(node);
     if(nameable != 0)
@@ -1275,7 +1283,9 @@ void node_attach_name_changed_callback(s
 }
 void node_detach_name_changed_callback(scene::Node& node, const NameCallback& callback)
 {
-  if(&node != 0)
+  volatile int n = (int)&node;		// see the comment on line 1246
+
+  if(n != 0)
   {
     Nameable* nameable = Node_getNameable(node);
     if(nameable != 0)
