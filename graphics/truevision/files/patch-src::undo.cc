--- src/undo.cc.orig	Tue Jan  1 20:43:01 2002
+++ src/undo.cc	Thu Jun 26 06:33:26 2003
@@ -181,7 +181,7 @@
 }
 
 // Undo layers creation / deletion / move		
-void UndoRedoManager::push( UndoAction act, ObjectLayer *lay, int sens = -1 )
+void UndoRedoManager::push( UndoAction act, ObjectLayer *lay, int sens )
 {
 UndoItem *item = new UndoItem( act, lay, sens );
 UndoList.push_back( item );
@@ -191,7 +191,7 @@
 }
 
 // Undo materials creation / deletion / move		
-void UndoRedoManager::push( UndoAction act, Material *mat, int position = -1 )
+void UndoRedoManager::push( UndoAction act, Material *mat, int position )
 {
 UndoItem *item = new UndoItem( act, mat, position );
 UndoList.push_back( item );
@@ -231,7 +231,7 @@
 // The main function used
 // in fact it is also used for redo ;-)
 //***************************************************
-void UndoRedoManager::undo( bool doredo = false )
+void UndoRedoManager::undo( bool doredo )
 {
 // Define source & destination lists
 // The determine if we act as undo or redo...
