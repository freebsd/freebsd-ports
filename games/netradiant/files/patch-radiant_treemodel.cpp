--- radiant/treemodel.cpp.orig	2013-06-30 14:04:35 UTC
+++ radiant/treemodel.cpp
@@ -647,7 +647,12 @@ void detach( const NameCallback& callbac
 };
 
 void node_attach_name_changed_callback( scene::Node& node, const NameCallback& callback ){
-	if ( &node != 0 ) {
+	// Reference cannot be bound to dereferenced null pointer in a
+	// well-defined C++ code, and Clang will assume that comparison
+	// below always evaluates to true, resulting in segmentation
+	// fault.  Use a dirty hack to force Clang to check for null.
+	volatile intptr_t n = (intptr_t)&node;
+	if ( n != 0 ) {
 		Nameable* nameable = Node_getNameable( node );
 		if ( nameable != 0 ) {
 			nameable->attach( callback );
@@ -655,7 +660,8 @@ void node_attach_name_changed_callback( 
 	}
 }
 void node_detach_name_changed_callback( scene::Node& node, const NameCallback& callback ){
-	if ( &node != 0 ) {
+	volatile intptr_t n = (intptr_t)&node;	// see the comment on line 650
+	if ( n != 0 ) {
 		Nameable* nameable = Node_getNameable( node );
 		if ( nameable != 0 ) {
 			nameable->detach( callback );
@@ -1124,7 +1130,8 @@ void graph_tree_model_row_deleted( Graph
 const char* node_get_name( scene::Node& node );
 
 const char* node_get_name_safe( scene::Node& node ){
-	if ( &node == 0 ) {
+	volatile intptr_t n = (intptr_t)&node;	// see the comment on line 650
+	if ( n == 0 ) {
 		return "";
 	}
 	return node_get_name( node );
@@ -1142,7 +1149,8 @@ GraphTreeNode* graph_tree_model_find_par
 }
 
 void node_attach_name_changed_callback( scene::Node& node, const NameCallback& callback ){
-	if ( &node != 0 ) {
+	volatile intptr_t n = (intptr_t)&node;	// see the comment on line 650
+	if ( n != 0 ) {
 		Nameable* nameable = Node_getNameable( node );
 		if ( nameable != 0 ) {
 			nameable->attach( callback );
@@ -1150,7 +1158,8 @@ void node_attach_name_changed_callback( 
 	}
 }
 void node_detach_name_changed_callback( scene::Node& node, const NameCallback& callback ){
-	if ( &node != 0 ) {
+	volatile intptr_t n = (intptr_t)&node;	// see the comment on line 650
+	if ( n != 0 ) {
 		Nameable* nameable = Node_getNameable( node );
 		if ( nameable != 0 ) {
 			nameable->detach( callback );
