--- PuyoGame.cpp.orig	2007-10-30 13:27:05.000000000 +0100
+++ PuyoGame.cpp	2007-10-30 13:28:39.000000000 +0100
@@ -45,7 +45,7 @@
 		return (PuyoState)newItem;
 	}
 	else
-		return (PuyoState)(int)(sequenceItems.getElementAt(sequence));
+		return (PuyoState)(long)(sequenceItems.getElementAt(sequence));
 }
 
 PuyoPuyo::PuyoPuyo(PuyoState state)
