--- dbd/myMsql.h.orig	Wed Nov 30 09:28:39 2005
+++ dbd/myMsql.h	Wed Nov 30 09:29:09 2005
@@ -117,7 +117,11 @@
 #define MyGetHostInfo(s) mysql_get_host_info(s)
 #define MyGetServerInfo(s) mysql_get_server_info(s)
 #define MyGetProtoInfo(s) mysql_get_proto_info(s)
+#if MYSQL_VERSION_ID < 40000
 #define MyShutdown(s) mysql_shutdown(s)
+#else
+#define MyShutdown(s) mysql_shutdown(s, SHUTDOWN_DEFAULT)
+#endif
 #ifdef REFRESH_GRANT
 #define MyReload(s) mysql_refresh(s, \
 				  REFRESH_GRANT|REFRESH_LOG|REFRESH_TABLES)
