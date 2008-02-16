--- php_mysqli.h.orig	2008-02-16 12:26:48.000000000 +0100
+++ php_mysqli.h	2008-02-16 12:30:02.000000000 +0100
@@ -291,10 +291,17 @@ PHP_MYSQLI_EXPORT(zend_object_value) mys
 #define MYSQLI_REPORT_CLOSE			8	
 #define MYSQLI_REPORT_ALL		  255
 
+#if MYSQL_VERSION_ID > 50122
+#define MYSQLI_REPORT_MYSQL_ERROR(mysql) \
+if ((MyG(report_mode) & MYSQLI_REPORT_ERROR) && mysql->net.client_last_errno) { \
+	php_mysqli_report_error(mysql->net.sqlstate, mysql->net.client_last_errno, mysql->net.client_last_error TSRMLS_CC); \
+}
+#else
 #define MYSQLI_REPORT_MYSQL_ERROR(mysql) \
 if ((MyG(report_mode) & MYSQLI_REPORT_ERROR) && mysql->net.last_errno) { \
 	php_mysqli_report_error(mysql->net.sqlstate, mysql->net.last_errno, mysql->net.last_error TSRMLS_CC); \
 }
+#endif
 
 #define MYSQLI_REPORT_STMT_ERROR(stmt) \
 if ((MyG(report_mode) & MYSQLI_REPORT_ERROR) && stmt->last_errno) { \
