--- bindings/c++/gdaConnection.cpp.orig	Sat Jun 15 17:02:32 2002
+++ bindings/c++/gdaConnection.cpp	Sat Jun 15 17:02:41 2002
@@ -294,7 +294,7 @@
 	return gda_connection_get_version (_gda_connection);
 }
 
-GdaConnection* Connection::getCStruct (bool refn = true) const
+GdaConnection* Connection::getCStruct (bool refn) const
 {
 	if (refn) ref ();
 	return _gda_connection;
