--- src/hoel-pgsql.c.orig	2020-02-11 23:34:18 UTC
+++ src/hoel-pgsql.c
@@ -118,7 +118,7 @@ struct _h_connection * h_connect_pgsql(const char * co
           pthread_mutexattr_init ( &mutexattr );
           pthread_mutexattr_settype( &mutexattr, PTHREAD_MUTEX_RECURSIVE );
           if (pthread_mutex_init(&(((struct _h_pgsql *)conn->connection)->lock), &mutexattr) != 0) {
-            y_log_message(Y_LOG_LEVEL_ERROR, "Impossible to initialize Mutex Lock for MariaDB connection");
+            y_log_message(Y_LOG_LEVEL_ERROR, "Impossible to initialize Mutex Lock for PostgreSQL connection");
           }
           pthread_mutexattr_destroy( &mutexattr );
         } else {
@@ -404,6 +404,42 @@ struct _h_connection * h_connect_pgsql(const char * co
 void h_close_pgsql(struct _h_connection * conn) {
   UNUSED(conn);
   y_log_message(Y_LOG_LEVEL_ERROR, "Hoel was not compiled with PostgreSQL backend");
+}
+
+char * h_escape_string_pgsql(const struct _h_connection * conn, const char * unsafe) {
+  UNUSED(conn);
+  UNUSED(unsafe);
+  y_log_message(Y_LOG_LEVEL_ERROR, "Hoel was not compiled with PostgreSQL backend");
+  return NULL;
+}
+
+char * h_escape_string_with_quotes_pgsql(const struct _h_connection * conn, const char * unsafe) {
+  UNUSED(conn);
+  UNUSED(unsafe);
+  y_log_message(Y_LOG_LEVEL_ERROR, "Hoel was not compiled with PostgreSQL backend");
+  return NULL;
+}
+
+long long int h_last_insert_id_pgsql(const struct _h_connection * conn) {
+  UNUSED(conn);
+  y_log_message(Y_LOG_LEVEL_ERROR, "Hoel was not compiled with PostgreSQL backend");
+  return 0;
+}
+
+int h_execute_query_pgsql(const struct _h_connection * conn, const char * query, struct _h_result * h_result) {
+  UNUSED(conn);
+  UNUSED(query);
+  UNUSED(h_result);
+  y_log_message(Y_LOG_LEVEL_ERROR, "Hoel was not compiled with PostgreSQL backend");
+  return H_ERROR;
+}
+
+int h_execute_query_json_pgsql(const struct _h_connection * conn, const char * query, json_t ** j_result) {
+  UNUSED(conn);
+  UNUSED(query);
+  UNUSED(j_result);
+  y_log_message(Y_LOG_LEVEL_ERROR, "Hoel was not compiled with PostgreSQL backend");
+  return H_ERROR;
 }
 
 #endif
