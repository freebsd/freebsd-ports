--- ai.cc.orig	Sat Oct 16 11:57:28 2004
+++ ai.cc	Sat Oct 16 11:57:45 2004
@@ -56,8 +56,8 @@
     height = arows;
     length = ((height+2) * (width+1) + 1);
 	
-    board = new (int)[length];
-    score = new (int)[length];
+    board = new int[length];
+    score = new int[length];
     for (int i=0; i<length; i++) {
 	board[i] = -1;
 	score[i] = -1;
