# https://github.com/abseil/abseil-cpp/commit/ded2ec077d911de647d47ab48ef3a8e24a1fb64a
# https://github.com/abseil/abseil-cpp/issues/1587
--- src/third_party/abseil-cpp/dist/absl/time/internal/cctz/src/time_zone_format.cc.orig	2024-07-23 13:17:01 UTC
+++ src/third_party/abseil-cpp/dist/absl/time/internal/cctz/src/time_zone_format.cc
@@ -19,7 +19,7 @@
 #endif
 
 #if defined(HAS_STRPTIME) && HAS_STRPTIME
-#if !defined(_XOPEN_SOURCE) && !defined(__OpenBSD__)
+#if !defined(_XOPEN_SOURCE) && !defined(__FreeBSD__) && !defined(__OpenBSD__)
 #define _XOPEN_SOURCE 500  // Exposes definitions for SUSv2 (UNIX 98).
 #endif
 #endif
