--- mysqli_nonapi.c.orig	2008-02-16 18:27:15.000000000 +0100
+++ mysqli_nonapi.c	2008-02-16 18:30:38.000000000 +0100
@@ -106,8 +106,13 @@ PHP_FUNCTION(mysqli_connect)
 	if (mysql_real_connect(mysql->mysql,hostname,username,passwd,dbname,port,socket,CLIENT_MULTI_RESULTS) == NULL) {
 		/* Save error messages */
 
+#if MYSQL_VERSION_ID > 50122
+		php_mysqli_throw_sql_exception( mysql->mysql->net.sqlstate, mysql->mysql->net.client_last_errno TSRMLS_CC,
+										"%s", mysql->mysql->net.client_last_error);
+#else
 		php_mysqli_throw_sql_exception( mysql->mysql->net.sqlstate, mysql->mysql->net.last_errno TSRMLS_CC,
 										"%s", mysql->mysql->net.last_error);
+#endif
 
 		php_mysqli_set_error(mysql_errno(mysql->mysql), (char *) mysql_error(mysql->mysql) TSRMLS_CC);
 
@@ -212,9 +217,14 @@ PHP_FUNCTION(mysqli_multi_query)
 		MYSQLI_DISABLE_MQ;
 
 		/* restore error information */
+#if MYSQL_VERSION_ID > 50122
+		strcpy(mysql->mysql->net.client_last_error, s_error);
+		mysql->mysql->net.client_last_errno = s_errno;	
+#else
 		strcpy(mysql->mysql->net.last_error, s_error);
-		strcpy(mysql->mysql->net.sqlstate, s_sqlstate);
 		mysql->mysql->net.last_errno = s_errno;	
+#endif
+		strcpy(mysql->mysql->net.sqlstate, s_sqlstate);
 
 		RETURN_FALSE;
 	}	
@@ -266,8 +276,13 @@ PHP_FUNCTION(mysqli_query)
 	result = (resultmode == MYSQLI_USE_RESULT) ? mysql_use_result(mysql->mysql) : mysql_store_result(mysql->mysql);
 
 	if (!result) {
+#if MYSQL_VERSION_ID > 50122
+		php_mysqli_throw_sql_exception(mysql->mysql->net.sqlstate, mysql->mysql->net.client_last_errno TSRMLS_CC,
+										"%s", mysql->mysql->net.client_last_error); 
+#else
 		php_mysqli_throw_sql_exception(mysql->mysql->net.sqlstate, mysql->mysql->net.last_errno TSRMLS_CC,
 										"%s", mysql->mysql->net.last_error); 
+#endif
 		RETURN_FALSE;
 	}
 
