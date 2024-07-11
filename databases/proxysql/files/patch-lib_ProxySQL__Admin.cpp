--- lib/ProxySQL_Admin.cpp.orig	2024-04-05 16:24:43 UTC
+++ lib/ProxySQL_Admin.cpp
@@ -9507,7 +9507,7 @@ void ProxySQL_Admin::p_update_metrics() {
  * @return On success, the number of currently opened file descriptors, '-1' otherwise.
  */
 int32_t get_open_fds() {
-	DIR* dir = opendir("/proc/self/fd");
+	DIR* dir = opendir("/dev/fd");
 	if (dir == NULL) {
 		proxy_error("'opendir()' failed with error: '%d'\n", errno);
 		return -1;
