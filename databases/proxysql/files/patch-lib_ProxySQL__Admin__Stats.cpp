--- lib/ProxySQL_Admin_Stats.cpp.orig	2026-07-30 16:48:30 UTC
+++ lib/ProxySQL_Admin_Stats.cpp
@@ -27,6 +27,11 @@
 // for reference) so no header from those moved sets is needed.
 #include <openssl/x509v3.h>
 
+#if defined(__FreeBSD__)
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#endif
+
 #define SAFE_SQLITE3_STEP(_stmt) do {\
   do {\
     rc=(*proxy_sqlite3_step)(_stmt);\
@@ -86,6 +91,19 @@ void ProxySQL_Admin::p_update_metrics() {
  * @return On success, the number of currently opened file descriptors, '-1' otherwise.
  */
 int32_t get_open_fds() {
+#if defined(__FreeBSD__)
+	// FreeBSD's procfs implementation does not provide /proc/self/fd
+	int mib[4] = { CTL_KERN, KERN_PROC, KERN_PROC_NFDS, 0 };
+	int nfds = 0;
+	size_t len = sizeof(nfds);
+
+	if (sysctl(mib, 4, &nfds, &len, NULL, 0) == -1) {
+		proxy_error("'sysctl(KERN_PROC_NFDS)' failed with error: '%d'\n", errno);
+		return -1;
+	}
+
+	return static_cast<int32_t>(nfds);
+#else
 	DIR* dir = opendir("/proc/self/fd");
 	if (dir == NULL) {
 		proxy_error("'opendir()' failed with error: '%d'\n", errno);
@@ -93,6 +111,8 @@ int32_t get_open_fds() {
 	}
 
 	struct dirent* dp = nullptr;
+	// Start at '-3' to discount the '.' and '..' entries, plus the fd
+	// opened by 'opendir()' itself.
 	int32_t count = -3;
 
 	while ((dp = readdir(dir)) != NULL) {
@@ -102,6 +122,7 @@ int32_t get_open_fds() {
 	closedir(dir);
 
 	return count;
+#endif
 }
 
 
