--- ./ImathTest/testBoxAlgo.cpp.orig	2013-06-18 21:51:38.000000000 +0200
+++ ./ImathTest/testBoxAlgo.cpp	2014-01-29 13:16:44.000000000 +0100
@@ -356,7 +356,7 @@
 	Box3f ()
     };
 
-    for (int i = 0; i < sizeof (boxes) / sizeof (boxes[0]); ++i)
+    for (unsigned int i = 0; i < sizeof (boxes) / sizeof (boxes[0]); ++i)
 	testEntryAndExitPoints (boxes[i]);
 }
 
