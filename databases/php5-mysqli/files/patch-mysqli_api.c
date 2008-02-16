--- mysqli_api.c.orig	2008-02-16 12:23:59.000000000 +0100
+++ mysqli_api.c	2008-02-16 12:32:26.000000000 +0100
@@ -1373,8 +1373,13 @@ PHP_FUNCTION(mysqli_prepare)
 			stmt->stmt = NULL;
 
 			/* restore error messages */
+#if MYSQL_VERSION_ID > 50122
+			mysql->mysql->net.client_last_errno = last_errno;
+			memcpy(mysql->mysql->net.client_last_error, last_error, MYSQL_ERRMSG_SIZE);
+#else
 			mysql->mysql->net.last_errno = last_errno;
 			memcpy(mysql->mysql->net.last_error, last_error, MYSQL_ERRMSG_SIZE);
+#endif
 			memcpy(mysql->mysql->net.sqlstate, sqlstate, SQLSTATE_LENGTH+1);
 		}
 	}
@@ -1450,8 +1455,13 @@ PHP_FUNCTION(mysqli_real_connect)
 
 	if (mysql_real_connect(mysql->mysql,hostname,username,passwd,dbname,port,socket,flags) == NULL) {
 		php_mysqli_set_error(mysql_errno(mysql->mysql), (char *) mysql_error(mysql->mysql) TSRMLS_CC);
+#if MYSQL_VERSION_ID > 50122
+		php_mysqli_throw_sql_exception( mysql->mysql->net.sqlstate, mysql->mysql->net.client_last_errno TSRMLS_CC,
+										"%s", mysql->mysql->net.client_last_error);
+#else
 		php_mysqli_throw_sql_exception( mysql->mysql->net.sqlstate, mysql->mysql->net.last_errno TSRMLS_CC,
 										"%s", mysql->mysql->net.last_error);
+#endif
 
 		/* change status */
 		MYSQLI_SET_STATUS(&mysql_link, MYSQLI_STATUS_INITIALIZED);
