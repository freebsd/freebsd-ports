--- src/hoel-mariadb.c.orig	2020-02-11 23:34:18 UTC
+++ src/hoel-mariadb.c
@@ -435,4 +435,48 @@ void h_close_mariadb(struct _h_connection * conn) {
   y_log_message(Y_LOG_LEVEL_ERROR, "Hoel was not compiled with MariaDB backend");
 }
 
+char * h_escape_string_mariadb(const struct _h_connection * conn, const char * unsafe) {
+  UNUSED(conn);
+  UNUSED(unsafe);
+  y_log_message(Y_LOG_LEVEL_ERROR, "Hoel was not compiled with MariaDB backend");
+  return NULL;
+}
+
+char * h_escape_string_with_quotes_mariadb(const struct _h_connection * conn, const char * unsafe) {
+  UNUSED(conn);
+  UNUSED(unsafe);
+  y_log_message(Y_LOG_LEVEL_ERROR, "Hoel was not compiled with MariaDB backend");
+  return NULL;
+}
+
+long long int h_last_insert_id_mariadb(const struct _h_connection * conn) {
+  UNUSED(conn);
+  y_log_message(Y_LOG_LEVEL_ERROR, "Hoel was not compiled with MariaDB backend");
+  return 0;
+}
+
+int h_execute_query_mariadb(const struct _h_connection * conn, const char * query, struct _h_result * h_result) {
+  UNUSED(conn);
+  UNUSED(query);
+  UNUSED(h_result);
+  y_log_message(Y_LOG_LEVEL_ERROR, "Hoel was not compiled with MariaDB backend");
+  return H_ERROR;
+}
+
+int h_execute_query_json_mariadb(const struct _h_connection * conn, const char * query, json_t ** j_result) {
+  UNUSED(conn);
+  UNUSED(query);
+  UNUSED(j_result);
+  y_log_message(Y_LOG_LEVEL_ERROR, "Hoel was not compiled with MariaDB backend");
+  return H_ERROR;
+}
+
+struct _h_data * h_get_mariadb_value(const char * value, const unsigned long length, const int m_type) {
+  UNUSED(value);
+  UNUSED(length);
+  UNUSED(m_type);
+  y_log_message(Y_LOG_LEVEL_ERROR, "Hoel was not compiled with MariaDB backend");
+  return NULL;
+}
+
 #endif
