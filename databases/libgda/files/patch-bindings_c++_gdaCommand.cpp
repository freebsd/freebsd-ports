--- bindings/c++/gdaCommand.cpp.orig	Sat Jun 15 17:02:00 2002
+++ bindings/c++/gdaCommand.cpp	Sat Jun 15 17:02:08 2002
@@ -139,7 +139,7 @@
 */
 
 GdaCommand*
-Command::getCStruct (bool refn = true) const
+Command::getCStruct (bool refn) const
 {
 	if (refn)
 		ref ();
