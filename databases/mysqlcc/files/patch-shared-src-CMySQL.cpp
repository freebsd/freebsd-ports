--- shared/src/CMySQL.cpp.orig	Thu Aug  5 12:26:14 2004
+++ shared/src/CMySQL.cpp	Thu Aug  5 12:29:53 2004
@@ -451,7 +451,11 @@
   if (!isConnected())
     return false;
   
+#if  ( MYSQL_VERSION_ID == 40103 ) || ( MYSQL_VERSION_ID == 50001 )
+  if (mysql_shutdown(mysql,SHUTDOWN_DEFAULT) != 0)
+#else
   if (mysql_shutdown(mysql) != 0)
+#endif
   {
     if (emiterror)
       emitError();
