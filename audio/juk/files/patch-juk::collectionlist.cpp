--- juk/collectionlist.cpp.orig	Sat Feb 15 08:36:32 2003
+++ juk/collectionlist.cpp	Mon Mar  3 12:24:34 2003
@@ -131,8 +131,8 @@
 {
     if(e->source() == this)
 	return;
-
-
+    else
+	decode(e);
 }
 
 void CollectionList::contentsDragMoveEvent(QDragMoveEvent *e)
