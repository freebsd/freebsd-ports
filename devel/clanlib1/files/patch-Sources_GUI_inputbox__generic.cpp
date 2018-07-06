--- Sources/GUI/inputbox_generic.cpp.orig	2008-04-18 11:16:05 UTC
+++ Sources/GUI/inputbox_generic.cpp
@@ -84,7 +84,7 @@ int CL_InputUndo::doUndo( std::string & 
 
 int CL_InputUndo::doRedo( std::string & text )
 {
-	if (!canRedo()) return NULL;
+	if (!canRedo()) return 0;
 
 	OneUndo const & u = undo_array[cur_pos];
 
