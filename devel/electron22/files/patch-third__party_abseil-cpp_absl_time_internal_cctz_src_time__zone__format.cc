--- third_party/abseil-cpp/absl/time/internal/cctz/src/time_zone_format.cc.orig	2022-09-24 10:57:32 UTC
+++ third_party/abseil-cpp/absl/time/internal/cctz/src/time_zone_format.cc
@@ -19,7 +19,7 @@
 #endif
 
 #if defined(HAS_STRPTIME) && HAS_STRPTIME
-#if !defined(_XOPEN_SOURCE) && !defined(__OpenBSD__)
+#if !defined(_XOPEN_SOURCE) && !defined(__OpenBSD__) && !defined(__FreeBSD__)
 #define _XOPEN_SOURCE  // Definedness suffices for strptime.
 #endif
 #endif
