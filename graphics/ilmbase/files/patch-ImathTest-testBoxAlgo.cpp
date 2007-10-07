--- ImathTest/testBoxAlgo.cpp.orig	2007-07-13 13:48:45.000000000 +0900
+++ ImathTest/testBoxAlgo.cpp	2007-10-07 23:26:22.000000000 +0900
@@ -336,7 +336,7 @@
 	Box3f ()
     };
 
-    for (int i = 0; i < sizeof (boxes) / sizeof (boxes[0]); ++i)
+    for (unsigned int i = 0; i < sizeof (boxes) / sizeof (boxes[0]); ++i)
 	testRayBoxIntersection (boxes[i]);
 }
 
