--- php_mssql.h	2005/12/06 01:25:16	1.42.2.1
+++ php_mssql.h	2005/12/21 22:43:06	1.42.2.2
@@ -158,6 +158,9 @@
 	zend_bool allow_persistent;
 	char *appname;
 	char *server_message;
+#ifdef HAVE_FREETDS
+	char *charset;
+#endif
 	long min_error_severity, min_message_severity;
 	long cfg_min_error_severity, cfg_min_message_severity;
 	long connect_timeout, timeout;
