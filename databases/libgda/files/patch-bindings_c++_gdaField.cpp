--- bindings/c++/gdaField.cpp.orig	Sat Jun 15 17:03:38 2002
+++ bindings/c++/gdaField.cpp	Sat Jun 15 17:03:45 2002
@@ -428,7 +428,7 @@
 }
 
 GdaField*
-Field::getCStruct (bool refn = true) const
+Field::getCStruct (bool refn) const
 {
 	if (refn) ref ();
 	return _gda_field;
