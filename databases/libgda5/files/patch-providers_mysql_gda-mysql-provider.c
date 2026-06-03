--- providers/mysql/gda-mysql-provider.c.orig	2020-11-08 20:23:20 UTC
+++ providers/mysql/gda-mysql-provider.c
@@ -1838,7 +1838,7 @@ real_prepare (GdaServerProvider *provider, GdaConnecti
 		return FALSE;
 	}
 
-	my_bool update_max_length = 1;
+	_Bool update_max_length = 1;
 	if (mysql_stmt_attr_set (mysql_stmt, STMT_ATTR_UPDATE_MAX_LENGTH, (const void *) &update_max_length)) {
 		_gda_mysql_make_error (cnc, NULL, mysql_stmt, error);
 		mysql_stmt_close (mysql_stmt);
@@ -1944,7 +1944,7 @@ prepare_stmt_simple (MysqlConnectionData  *cdata,
 		return FALSE;
 	}
 
-	my_bool update_max_length = 1;
+	_Bool update_max_length = 1;
 	if (mysql_stmt_attr_set (mysql_stmt, STMT_ATTR_UPDATE_MAX_LENGTH, (const void *) &update_max_length)) {
 		_gda_mysql_make_error (cdata->cnc, NULL, mysql_stmt, error);
 		mysql_stmt_close (mysql_stmt);
@@ -2330,7 +2330,7 @@ gda_mysql_provider_statement_execute (GdaServerProvide
 			if (allow_noparam) {
                                 /* bind param to NULL */
 				mysql_bind_param[i].buffer_type = MYSQL_TYPE_NULL;
-				mysql_bind_param[i].is_null = (my_bool*)1;
+				mysql_bind_param[i].is_null = (_Bool *) 1;
                                 empty_rs = TRUE;
                                 continue;
 			}
@@ -2350,7 +2350,7 @@ gda_mysql_provider_statement_execute (GdaServerProvide
 			if (allow_noparam) {
                                 /* bind param to NULL */
 				mysql_bind_param[i].buffer_type = MYSQL_TYPE_NULL;
-				mysql_bind_param[i].is_null = (my_bool*)1;
+				mysql_bind_param[i].is_null = (_Bool *) 1;
                                 empty_rs = TRUE;
                                 continue;
 			}
@@ -2402,7 +2402,7 @@ gda_mysql_provider_statement_execute (GdaServerProvide
 			GdaStatement *rstmt;
 			if (! gda_rewrite_statement_for_null_parameters (stmt, params, &rstmt, error)) {
 				mysql_bind_param[i].buffer_type = MYSQL_TYPE_NULL;
-				mysql_bind_param[i].is_null = (my_bool*)1;
+				mysql_bind_param[i].is_null = (_Bool *) 1;
 			}
 			else if (!rstmt)
 				return NULL;
@@ -2462,7 +2462,7 @@ gda_mysql_provider_statement_execute (GdaServerProvide
 			ts = (GdaTimestamp*) gda_value_get_timestamp (value);
 			if (!ts) {
 				mysql_bind_param[i].buffer_type = MYSQL_TYPE_NULL;
-				mysql_bind_param[i].is_null = (my_bool*)1;
+				mysql_bind_param[i].is_null = (_Bool *) 1;
 			}
 			else {
 				gboolean tofree = FALSE;
@@ -2498,7 +2498,7 @@ gda_mysql_provider_statement_execute (GdaServerProvide
 			ts = (GdaTime*) gda_value_get_time (value);
 			if (!ts) {
 				mysql_bind_param[i].buffer_type = MYSQL_TYPE_NULL;
-				mysql_bind_param[i].is_null = (my_bool*)1;
+				mysql_bind_param[i].is_null = (_Bool *) 1;
 			}
 			else {
 				gboolean tofree = FALSE;
@@ -2531,7 +2531,7 @@ gda_mysql_provider_statement_execute (GdaServerProvide
 			ts = (GDate*) g_value_get_boxed (value);
 			if (!ts) {
 				mysql_bind_param[i].buffer_type = MYSQL_TYPE_NULL;
-				mysql_bind_param[i].is_null = (my_bool*)1;
+				mysql_bind_param[i].is_null = (_Bool *) 1;
 			}
 			else {
 				MYSQL_TIME *mtime;
@@ -2551,7 +2551,7 @@ gda_mysql_provider_statement_execute (GdaServerProvide
 			str = g_value_get_string (value);
 			if (!str) {
 				mysql_bind_param[i].buffer_type = MYSQL_TYPE_NULL;
-				mysql_bind_param[i].is_null = (my_bool*)1;
+				mysql_bind_param[i].is_null = (_Bool *) 1;
 			}
 			else {
 				mysql_bind_param[i].buffer_type= MYSQL_TYPE_STRING;
@@ -2627,7 +2627,7 @@ gda_mysql_provider_statement_execute (GdaServerProvide
 			bin = ((GdaBinary*) blob);
 			if (!bin) {
 				mysql_bind_param[i].buffer_type = MYSQL_TYPE_NULL;
-				mysql_bind_param[i].is_null = (my_bool*)1;
+				mysql_bind_param[i].is_null = (_Bool *) 1;
 			}
 			else {
 				gchar *str = NULL;
@@ -2668,7 +2668,7 @@ gda_mysql_provider_statement_execute (GdaServerProvide
 			bin = gda_value_get_binary (value);
 			if (!bin) {
 				mysql_bind_param[i].buffer_type = MYSQL_TYPE_NULL;
-				mysql_bind_param[i].is_null = (my_bool*)1;
+				mysql_bind_param[i].is_null = (_Bool *) 1;
 			}
 			else {
 				mysql_bind_param[i].buffer_type= MYSQL_TYPE_BLOB;
