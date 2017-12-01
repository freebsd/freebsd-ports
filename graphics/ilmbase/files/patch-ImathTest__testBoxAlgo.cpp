--- ImathTest/testBoxAlgo.cpp.orig	2017-11-17 23:00:23 UTC
+++ ImathTest/testBoxAlgo.cpp
@@ -356,7 +356,7 @@ entryAndExitPoints1 ()
 	Box3f ()
     };
 
-    for (int i = 0; i < sizeof (boxes) / sizeof (boxes[0]); ++i)
+    for (unsigned int i = 0; i < sizeof (boxes) / sizeof (boxes[0]); ++i)
 	testEntryAndExitPoints (boxes[i]);
 }
 
