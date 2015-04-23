--- radiant/treemodel.cpp.orig	2006-02-10 22:01:20 UTC
+++ radiant/treemodel.cpp
@@ -710,7 +710,13 @@ public:
 
 void node_attach_name_changed_callback(scene::Node& node, const NameCallback& callback)
 {
-  if(&node != 0)
+  // Reference cannot be bound to dereferenced null pointer in well-defined
+  // C++ code, and Clang will assume that comparison below always evaluates
+  // to true, resulting in a segmentation fault.  Use a dirty hack to force
+  // Clang to check those "bad" references for null nonetheless.
+  volatile intptr_t n = (intptr_t)&node;
+
+  if(n != 0)
   {
     Nameable* nameable = Node_getNameable(node);
     if(nameable != 0)
@@ -721,7 +727,9 @@ void node_attach_name_changed_callback(s
 }
 void node_detach_name_changed_callback(scene::Node& node, const NameCallback& callback)
 {
-  if(&node != 0)
+  volatile intptr_t n = (intptr_t)&node;	// see the comment on line 713
+
+  if(n != 0)
   {
     Nameable* nameable = Node_getNameable(node);
     if(nameable != 0)
@@ -1243,7 +1251,9 @@ const char* node_get_name(scene::Node& n
 
 const char* node_get_name_safe(scene::Node& node)
 {
-  if(&node == 0)
+  volatile intptr_t n = (intptr_t)&node;	// see the comment on line 713
+
+  if(n == 0)
   {
     return "";
   }
@@ -1264,7 +1274,9 @@ GraphTreeNode* graph_tree_model_find_par
 
 void node_attach_name_changed_callback(scene::Node& node, const NameCallback& callback)
 {
-  if(&node != 0)
+  volatile intptr_t n = (intptr_t)&node;	// see the comment on line 713
+
+  if(n != 0)
   {
     Nameable* nameable = Node_getNameable(node);
     if(nameable != 0)
@@ -1275,7 +1287,9 @@ void node_attach_name_changed_callback(s
 }
 void node_detach_name_changed_callback(scene::Node& node, const NameCallback& callback)
 {
-  if(&node != 0)
+  volatile intptr_t n = (intptr_t)&node;	// see the comment on line 713
+
+  if(n != 0)
   {
     Nameable* nameable = Node_getNameable(node);
     if(nameable != 0)
