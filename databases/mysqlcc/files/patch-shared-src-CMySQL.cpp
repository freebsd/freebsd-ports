--- shared/src/CMySQL.cpp.orig	Sun Dec 14 00:10:44 2003
+++ shared/src/CMySQL.cpp	Sun Dec 26 14:24:43 2004
@@ -450,8 +450,12 @@
   
   if (!isConnected())
     return false;
-  
+
+#if  ( MYSQL_VERSION_ID == 40103 ) || ( MYSQL_VERSION_ID == 50001 ) || ( MYSQL_VERSION_ID == 40107 )
+  if (mysql_shutdown(mysql,SHUTDOWN_DEFAULT) != 0)
+#else
   if (mysql_shutdown(mysql) != 0)
+#endif
   {
     if (emiterror)
       emitError();
