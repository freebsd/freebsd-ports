--- include/swoole_async.h.orig	2024-11-28 03:39:05 UTC
+++ include/swoole_async.h
@@ -23,6 +23,11 @@
 #include <mutex>
 #include <atomic>
 
+#ifdef __FreeBSD__
+#include <arpa/inet.h>
+#include <netinet/in.h>
+#endif
+
 #ifndef O_DIRECT
 #define O_DIRECT 040000
 #endif
