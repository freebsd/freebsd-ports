--- lib/ProxySQL_Admin.cpp.orig	2025-11-05 18:44:48 UTC
+++ lib/ProxySQL_Admin.cpp
@@ -332,7 +332,7 @@ char rand_del[6];
 char rand_del[6];
 
 //static int http_handler(void *cls, struct MHD_Connection *connection, const char *url, const char *method, const char *version, const char *upload_data, size_t *upload_data_size, void **ptr) {
-MHD_Result http_handler(void *cls, struct MHD_Connection *connection, const char *url, const char *method, const char *version, const char *upload_data, long unsigned int *upload_data_size, void **ptr) {
+MHD_Result http_handler(void *cls, struct MHD_Connection *connection, const char *url, const char *method, const char *version, const char *upload_data, size_t *upload_data_size, void **ptr) {
 	return (MHD_Result) GloAdmin->AdminHTTPServer->handler(cls, connection, url, method, version, upload_data, upload_data_size, ptr);
 }
 
