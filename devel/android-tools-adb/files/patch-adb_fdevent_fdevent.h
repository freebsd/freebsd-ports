--- adb/fdevent/fdevent.h.orig	2019-07-17 19:54:09 UTC
+++ adb/fdevent/fdevent.h
@@ -20,6 +20,7 @@
 #include <stddef.h>
 #include <stdint.h>
 
+#include <atomic> // std::atomic<bool> for GCC
 #include <chrono>
 #include <deque>
 #include <functional>
