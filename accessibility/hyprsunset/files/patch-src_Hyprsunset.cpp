--- src/Hyprsunset.cpp.orig	2025-10-03 22:29:52 UTC
+++ src/Hyprsunset.cpp
@@ -1,13 +1,29 @@
 #include "ConfigManager.hpp"
 #include "helpers/Log.hpp"
 #include "IPCSocket.hpp"
+#include <algorithm>
 #include <cstring>
 #include <mutex>
 #include <thread>
 #include <chrono>
+#include <signal.h>
 #include <sys/poll.h>
 #include <sys/timerfd.h>
+#include <unistd.h>
 #include <wayland-client-core.h>
+
+#if defined(_LIBCPP_HAS_NO_TIME_ZONE_DATABASE) || \
+  (defined(_LIBCPP_HAS_TIME_ZONE_DATABASE) && \
+  _LIBCPP_HAS_TIME_ZONE_DATABASE == 0)
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
 
