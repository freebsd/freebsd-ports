--- mysqlcppapi/Connection.cc.orig	Wed Aug  4 23:15:58 2004
+++ mysqlcppapi/Connection.cc	Wed Aug  4 23:18:13 2004
@@ -211,9 +211,11 @@
 bool Connection::shutdown ()
 {
   check_connection_is_open();
-  
+#if  ( MYSQL_VERSION_ID >= 50001 ) || (( MYSQL_VERSION_ID < 50000 ) && ( MYSQL_VERSION_ID >= 40103 ))
+  bool suc = !(mysql_shutdown(m_sharedptr_connection.obj(),SHUTDOWN_DEFAULT));
+#else
   bool suc = !(mysql_shutdown(m_sharedptr_connection.obj()));
-
+#endif
   if (!suc)
     throw ex_BadQuery(error());
 
