Backport of Perfetto's FreeBSD support (upstream 81c39c7f82, Perfetto
v53) to the Perfetto that Dart 3.13 pins (series 1001). Drop it once
Dart pins Perfetto v53 or later.
--- third_party/perfetto/src/include/perfetto/base/time.h.orig	2026-09-29 08:00:52 UTC
+++ third_party/perfetto/src/include/perfetto/base/time.h
@@ -181,7 +181,12 @@ inline TimeNanos GetWallTimeRawNs() {
 }
 
 inline TimeNanos GetWallTimeRawNs() {
+#if defined(__FreeBSD__)
+  // CLOCK_MONOTONIC_RAW is a Linux extension.
+  return GetTimeInternalNs(CLOCK_MONOTONIC);
+#else
   return GetTimeInternalNs(CLOCK_MONOTONIC_RAW);
+#endif
 }
 
 inline TimeNanos GetThreadCPUTimeNs() {
