--- lib/proxysql_utils.cpp.orig	2026-03-20 19:16:36 UTC
+++ lib/proxysql_utils.cpp
@@ -23,6 +23,10 @@
 #ifdef __linux__
 #include <linux/close_range.h>
 #endif
+#ifdef __FreeBSD__
+#include <sys/socket.h>
+#include <netinet/in.h>
+#endif
 
 using std::function;
 using std::string;
