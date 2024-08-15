--- third_party/perfetto/include/perfetto/base/time.h.orig	2024-06-18 21:44:51 UTC
+++ third_party/perfetto/include/perfetto/base/time.h
@@ -201,6 +201,9 @@ inline TimeNanos GetBootTimeNs() {
 // Return ns from boot. Conversely to GetWallTimeNs, this clock counts also time
 // during suspend (when supported).
 inline TimeNanos GetBootTimeNs() {
+#if defined(__FreeBSD__)
+  return GetTimeInternalNs(kWallTimeClockSource);
+#else
   // Determine if CLOCK_BOOTTIME is available on the first call.
   static const clockid_t kBootTimeClockSource = [] {
     struct timespec ts = {};
@@ -208,6 +211,7 @@ inline TimeNanos GetBootTimeNs() {
     return res == 0 ? CLOCK_BOOTTIME : kWallTimeClockSource;
   }();
   return GetTimeInternalNs(kBootTimeClockSource);
+#endif
 }
 
 inline TimeNanos GetWallTimeNs() {
@@ -215,7 +219,13 @@ inline TimeNanos GetWallTimeRawNs() {
 }
 
 inline TimeNanos GetWallTimeRawNs() {
+#if defined(__OpenBSD__)
+  return GetTimeInternalNs(CLOCK_MONOTONIC);
+#elif defined(__FreeBSD__)
+  return GetTimeInternalNs(CLOCK_MONOTONIC_FAST);
+#else
   return GetTimeInternalNs(CLOCK_MONOTONIC_RAW);
+#endif
 }
 
 inline TimeNanos GetThreadCPUTimeNs() {
