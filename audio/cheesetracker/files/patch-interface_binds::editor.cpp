--- interface_binds/editor.cpp.orig	Fri Sep 17 11:15:06 2004
+++ interface_binds/editor.cpp	Fri Sep 17 11:30:35 2004
@@ -358,7 +358,7 @@
 
 void Editor::set_note_increment_table(Uint8* p_table) {
 
-	(Uint8*)note_increments=p_table;
+	note_increments=(char*)p_table;
 
 }
 
