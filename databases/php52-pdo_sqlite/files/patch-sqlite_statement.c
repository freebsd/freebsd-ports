--- sqlite_statement.c.orig	2007-12-31 08:20:10.000000000 +0100
+++ sqlite_statement.c	2008-12-07 11:50:35.000000000 +0100
@@ -104,6 +104,21 @@
 						pdo_sqlite_error_stmt(stmt);
 						return 0;
 					
+					case PDO_PARAM_INT:
+					case PDO_PARAM_BOOL:
+						if (Z_TYPE_P(param->parameter) == IS_NULL) {
+							if (sqlite3_bind_null(S->stmt, param->paramno + 1) == SQLITE_OK) {
+								return 1;
+							}
+						} else {
+							convert_to_long(param->parameter);
+							if (SQLITE_OK == sqlite3_bind_int(S->stmt, param->paramno + 1, Z_LVAL_P(param->parameter))) {
+								return 1;
+							}
+						}
+						pdo_sqlite_error_stmt(stmt);
+						return 0;
+
 					case PDO_PARAM_LOB:
 						if (Z_TYPE_P(param->parameter) == IS_RESOURCE) {
 							php_stream *stm;
@@ -117,8 +132,24 @@
 								pdo_raise_impl_error(stmt->dbh, stmt, "HY105", "Expected a stream resource" TSRMLS_CC);
 								return 0;
 							}
+						} else if (Z_TYPE_P(param->parameter) == IS_NULL) {
+							if (sqlite3_bind_null(S->stmt, param->paramno + 1) == SQLITE_OK) {
+								return 1;
+							}
+							pdo_sqlite_error_stmt(stmt);
+							return 0;
+						} else {
+							convert_to_string(param->parameter);
+ 						}
+
+						if (SQLITE_OK == sqlite3_bind_blob(S->stmt, param->paramno + 1,
+								Z_STRVAL_P(param->parameter),
+								Z_STRLEN_P(param->parameter),
+								SQLITE_STATIC)) {
+							return 1;
 						}
-						/* fall through */
+						pdo_sqlite_error_stmt(stmt);
+						return 0;
 		
 					case PDO_PARAM_STR:
 					default:
