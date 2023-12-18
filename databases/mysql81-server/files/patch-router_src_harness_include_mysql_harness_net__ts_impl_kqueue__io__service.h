--- router/src/harness/include/mysql/harness/net_ts/impl/kqueue_io_service.h.orig	2023-06-21 07:52:10 UTC
+++ router/src/harness/include/mysql/harness/net_ts/impl/kqueue_io_service.h
@@ -190,8 +190,8 @@ class kqueue_io_service : public IoServiceBase {
         auto secs = std::chrono::duration_cast<std::chrono::seconds>(timeout);
         timeout -= secs;
 
-        ts = {secs.count(),
-              std::chrono::duration_cast<std::chrono::nanoseconds>(timeout)
+        ts = {(time_t)secs.count(),
+              (long)std::chrono::duration_cast<std::chrono::nanoseconds>(timeout)
                   .count()};
 
         p_ts = &ts;
