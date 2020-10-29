--- router/src/harness/include/mysql/harness/net_ts/impl/kqueue_io_service.h.orig	2020-09-23 12:37:48 UTC
+++ router/src/harness/include/mysql/harness/net_ts/impl/kqueue_io_service.h
@@ -190,8 +190,8 @@
         auto secs = std::chrono::duration_cast<std::chrono::seconds>(timeout);
         timeout -= secs;
 
-        ts = {secs.count(),
-              std::chrono::duration_cast<std::chrono::nanoseconds>(timeout)
+        ts = {(time_t)secs.count(),
+              (time_t)std::chrono::duration_cast<std::chrono::nanoseconds>(timeout)
                   .count()};
 
         p_ts = &ts;
