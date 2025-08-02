--- src/Hyprsunset.cpp.orig	2025-07-24 17:32:18 UTC
+++ src/Hyprsunset.cpp
@@ -5,9 +5,22 @@
 #include <mutex>
 #include <thread>
 #include <chrono>
+#include <signal.h>
 #include <sys/poll.h>
 #include <sys/timerfd.h>
+#include <unistd.h>
 #include <wayland-client-core.h>
+
+#if defined(_LIBCPP_VERSION) || defined(_LIBCPP_HAS_NO_TIME_ZONE_DATABASE)
+#pragma comment(lib, "date-tz")
+#include <date/tz.h>
+namespace std {
+    namespace chrono {
+        using date::current_zone;
+        using date::zoned_time;
+    }
+}
+#endif
 
 #define TIMESPEC_NSEC_PER_SEC 1000000000L
 
