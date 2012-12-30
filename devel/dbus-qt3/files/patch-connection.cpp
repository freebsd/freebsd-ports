--- connection.cpp.orig	2006-07-18 16:15:13.000000000 +0400
+++ connection.cpp	2008-05-30 00:09:02.000000000 +0400
@@ -106,7 +106,7 @@
 
 void Connection::close()
 {
-  dbus_connection_close( d->connection );
+  dbus_connection_unref( d->connection );
 }
 
 void Connection::flush()
@@ -154,6 +154,7 @@
 
 void* Connection::virtual_hook( int, void*  )
 {
+  return (void *)NULL;
 }
 
 void Connection::dbus_connection_setup_with_qt_main (DBusConnection *connection)
