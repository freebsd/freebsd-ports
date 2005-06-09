
$FreeBSD$

--- shared/src/CMySQL.cpp.orig
+++ shared/src/CMySQL.cpp
@@ -450,8 +450,12 @@
   
   if (!isConnected())
     return false;
-  
+
+#if  ( MYSQL_VERSION_ID > 40100 ) || ( MYSQL_VERSION_ID == 50001 ) || ( MYSQL_VERSION_ID == 40107 )
+  if (mysql_shutdown(mysql,SHUTDOWN_DEFAULT) != 0)
+#else
   if (mysql_shutdown(mysql) != 0)
+#endif
   {
     if (emiterror)
       emitError();
