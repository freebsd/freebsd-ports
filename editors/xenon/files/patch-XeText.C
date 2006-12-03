--- XeText.C.orig	Sat Jan  5 20:39:39 2002
+++ XeText.C	Fri Dec  1 21:25:34 2006
@@ -1612,26 +1612,19 @@
 	
 	if(_numUndos >= _maxUndos) {
 		
-		// $$$ calling previous() here assums _undoList is not empty
-		// previous() is O(N) where N is the number of undo items in the list
-		// if this turns out to be too much of a performance penalty, use
-		// std::list instead of std::slist for _undoList
-		
-		std::slist<Undo*>::iterator pos = _undoList.previous(_undoList.end());
-		Undo* undo = *pos;
+		Undo* undo = _undoList.back();
 		
 		_undoBuf.remove(KRBUF_END, _undoBuf.length() - undo->len);
 		delete undo;
-		_undoList.erase(pos);
+		_undoList.pop_back();
 		
 		if (!_undoList.empty()) {
-			pos = _undoList.previous(_undoList.end());
-			undo = *pos;
+			undo = _undoList.back();
 			
 			if (undo && undo->type == InsertSelection) {
 				_undoBuf.remove(KRBUF_END, _undoBuf.length() - undo->len);
 				delete undo;
-				_undoList.erase(pos);
+				_undoList.pop_back();
 			}
 		}
 		
