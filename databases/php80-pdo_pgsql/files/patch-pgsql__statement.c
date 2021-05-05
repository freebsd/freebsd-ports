--- pgsql_statement.c.orig	2021-05-05 08:26:44 UTC
+++ pgsql_statement.c
@@ -52,21 +52,6 @@
 #define VARCHARLABEL "varchar"
 #define VARCHAROID   1043
 
-#define PG_INT32_MIN	(-0x7FFFFFFF-1)
-#define PG_INT32_MAX	(0x7FFFFFFF)
-
-#if defined(_MSC_VER)
-# define strtoll(s, f, b) _atoi64(s)
-#elif !defined(HAVE_STRTOLL)
-# if defined(HAVE_ATOLL)
-#  define strtoll(s, f, b) atoll(s)
-# else
-#  define strtoll(s, f, b) strtol(s, f, b)
-# endif
-#endif
-
-
-
 static int pgsql_stmt_dtor(pdo_stmt_t *stmt)
 {
 	pdo_pgsql_stmt *S = (pdo_pgsql_stmt*)stmt->driver_data;
@@ -401,16 +386,7 @@ static int pgsql_stmt_param_hook(pdo_stmt_t *stmt, str
 						S->param_formats[param->paramno] = 0;
 					}
 
-					if (PDO_PARAM_TYPE(param->param_type) == PDO_PARAM_INT) {
-						/* we need to check if the number requires bigints */
-						long long val = strtoll(Z_STRVAL_P(parameter), NULL, 10);
-
-						if (val > PG_INT32_MAX || val < PG_INT32_MIN) {
-							S->param_types[param->paramno] = INT8OID;
-						} else {
-							S->param_types[param->paramno] = INT4OID;
-						}
-					} else if (PDO_PARAM_TYPE(param->param_type) == PDO_PARAM_LOB) {
+					if (PDO_PARAM_TYPE(param->param_type) == PDO_PARAM_LOB) {
 						S->param_types[param->paramno] = 0;
 						S->param_formats[param->paramno] = 1;
 					} else {
