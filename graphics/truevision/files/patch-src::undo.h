--- src/undo.h.orig	Tue Jan  1 20:43:01 2002
+++ src/undo.h	Thu Jun 26 02:21:52 2003
@@ -65,7 +65,7 @@
 // one for undo and the other for redo
 //**********************************************************
 class UndoItem {
-	friend UndoRedoManager;
+	friend struct UndoRedoManager;
 
 	private:
 		UndoAction action;
