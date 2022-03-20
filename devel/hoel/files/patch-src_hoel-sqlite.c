--- src/hoel-sqlite.c.orig	2020-02-11 23:34:18 UTC
+++ src/hoel-sqlite.c
@@ -212,6 +212,20 @@ int h_select_query_sqlite(const struct _h_connection *
  * return H_OK on success
  */
 int h_exec_query_sqlite(const struct _h_connection * conn, const char * query) {
+  return h_execute_query_sqlite(conn, query);
+}
+
+/**
+ * h_execute_query_sqlite
+ * Execute a query on a sqlite connection
+ * This is an internal function, you should use h_exec_query instead
+ * Should not be executed by the user because all parameters are supposed to be correct
+ * No result is returned, useful for single INSERT, UPDATE or DELETE statements
+ * @param conn the connection to the database
+ * @param query the SQL query to execute
+ * @return H_OK on success
+ */
+int h_execute_query_sqlite(const struct _h_connection * conn, const char * query) {
   if (sqlite3_exec(((struct _h_sqlite *)conn->connection)->db_handle, query, NULL, NULL, NULL) == SQLITE_OK) {
     return H_OK;
   } else {
@@ -222,7 +236,6 @@ int h_exec_query_sqlite(const struct _h_connection * c
     y_log_message(Y_LOG_LEVEL_DEBUG, "Query: \"%s\"", query);
     return H_ERROR_QUERY;
   }
-  
 }
 
 /**
@@ -309,6 +322,48 @@ struct _h_connection * h_connect_sqlite(const char * d
 void h_close_sqlite(struct _h_connection * conn) {
   UNUSED(conn);
   y_log_message(Y_LOG_LEVEL_ERROR, "Hoel was not compiled with SQLite backend");
+}
+
+char * h_escape_string_sqlite(const struct _h_connection * conn, const char * unsafe) {
+  UNUSED(conn);
+  UNUSED(unsafe);
+  y_log_message(Y_LOG_LEVEL_ERROR, "Hoel was not compiled with SQLite backend");
+  return NULL;
+}
+
+char * h_escape_string_with_quotes_sqlite(const struct _h_connection * conn, const char * unsafe) {
+  UNUSED(conn);
+  UNUSED(unsafe);
+  y_log_message(Y_LOG_LEVEL_ERROR, "Hoel was not compiled with SQLite backend");
+  return NULL;
+}
+
+long long int h_last_insert_id_sqlite(const struct _h_connection * conn) {
+  UNUSED(conn);
+  y_log_message(Y_LOG_LEVEL_ERROR, "Hoel was not compiled with SQLite backend");
+  return 0;
+}
+
+int h_exec_query_sqlite(const struct _h_connection * conn, const char * query) {
+  UNUSED(conn);
+  UNUSED(query);
+  y_log_message(Y_LOG_LEVEL_ERROR, "Hoel was not compiled with SQLite backend");
+  return H_ERROR;
+}
+
+int h_execute_query_sqlite(const struct _h_connection * conn, const char * query) {
+  UNUSED(conn);
+  UNUSED(query);
+  y_log_message(Y_LOG_LEVEL_ERROR, "Hoel was not compiled with SQLite backend");
+  return H_ERROR;
+}
+
+int h_execute_query_json_sqlite(const struct _h_connection * conn, const char * query, json_t ** j_result) {
+  UNUSED(conn);
+  UNUSED(query);
+  UNUSED(j_result);
+  y_log_message(Y_LOG_LEVEL_ERROR, "Hoel was not compiled with SQLite backend");
+  return H_ERROR;
 }
 
 #endif
