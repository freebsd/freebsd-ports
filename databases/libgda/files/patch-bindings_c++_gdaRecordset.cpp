--- bindings/c++/gdaRecordset.cpp.orig	Sat Jun 15 17:05:30 2002
+++ bindings/c++/gdaRecordset.cpp	Sat Jun 15 17:05:55 2002
@@ -254,7 +254,7 @@
 }
 
 GdaRecordset*
-Recordset::getCStruct (bool refn = true) const
+Recordset::getCStruct (bool refn) const
 {
 	if (refn) ref ();
 	return _gda_recordset;
