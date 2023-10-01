--- include/swoole_async.h.orig	2023-10-01 04:44:15 UTC
+++ include/swoole_async.h
@@ -23,6 +23,10 @@
 #include <mutex>
 #include <atomic>
 
+#ifdef __FreeBSD__
+#include <arpa/inet.h>
+#endif
+
 #ifndef O_DIRECT
 #define O_DIRECT 040000
 #endif
