--- picport.cc.orig	Tue Nov 19 12:52:11 2002
+++ picport.cc	Tue Nov 19 12:52:20 2002
@@ -192,7 +192,7 @@
 
 // -1 == error, no programmer present
 
-int picport::command (enum commands comm, int data = 0)
+int picport::command (enum commands comm, int data)
 {
   int tmp1, tmp2;
 
