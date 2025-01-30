--- src/timg-time.h.orig	2025-01-30 13:44:32 UTC
+++ src/timg-time.h
@@ -50,13 +50,13 @@ class Duration { (public)
     }
 
     static constexpr Duration Millis(int64_t ms) {
-        return {ms / 1000, (ms % 1000) * 1000000};
+        return {static_cast<time_t>(ms / 1000), static_cast<long>((ms % 1000) * 1000000)};
     }
     static constexpr Duration Micros(int64_t usec) {
-        return {usec / 1000, (usec % 1000000) * 1000};
+        return {static_cast<time_t>(usec / 1000), static_cast<long>((usec % 1000000) * 1000)};
     }
     static constexpr Duration Nanos(int64_t nanos) {
-        return {nanos / 1000000000, nanos % 1000000000};
+        return {static_cast<time_t>(nanos / 1000000000), static_cast<long>(nanos % 1000000000)};
     }
     static constexpr Duration InfiniteFuture() {
         return {1000000000, 0};  // a few years; infinite enough :)
