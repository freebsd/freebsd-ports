--- bindings/c++/gdaBatch.cpp.orig	Sat Jun 15 17:01:27 2002
+++ bindings/c++/gdaBatch.cpp	Sat Jun 15 17:01:41 2002
@@ -127,7 +127,7 @@
 }
 
 GdaBatch*
-Batch::getCStruct (bool refn = true) const
+Batch::getCStruct (bool refn) const
 {
 	if (refn)
 	  ref ();
