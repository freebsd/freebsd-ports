--- ImathTest/testBoxAlgo.cpp.orig	2012-07-18 01:27:26.000000000 +0200
+++ ImathTest/testBoxAlgo.cpp	2012-10-04 15:45:00.000000000 +0200
@@ -356,7 +356,7 @@
 	Box3f ()
     };
 
-    for (int i = 0; i < sizeof (boxes) / sizeof (boxes[0]); ++i)
+    for (unsigned int i = 0; i < sizeof (boxes) / sizeof (boxes[0]); ++i)
 	testEntryAndExitPoints (boxes[i]);
 }
 
