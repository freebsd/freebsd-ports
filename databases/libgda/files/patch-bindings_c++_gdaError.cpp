--- bindings/c++/gdaError.cpp.orig	Sat Jun 15 17:03:02 2002
+++ bindings/c++/gdaError.cpp	Sat Jun 15 17:03:09 2002
@@ -98,7 +98,7 @@
 }
 
 GdaError*
-Error::getCStruct (bool refn = true) const
+Error::getCStruct (bool refn) const
 {
 	if (refn) ref ();
 	return _gda_error;
