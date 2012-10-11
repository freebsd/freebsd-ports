--- Stack.cpp.orig	2012-10-09 17:42:07.000000000 +0200
+++ Stack.cpp	2012-10-09 17:42:30.000000000 +0200
@@ -53,7 +53,8 @@
 int Stack::height()
 {
 	// return the height of the stack in elements
-	return ((unsigned int) top - (unsigned int) bottom)/sizeof(stackval);
+       // magic of pointer math returns number of elements
+       return ((int) (top - bottom));
 }
 
 void
