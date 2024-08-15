--- extra/abseil/abseil-cpp-20230802.1/absl/time/internal/cctz/src/time_zone_format.cc.orig	2024-07-26 08:50:41 UTC
+++ extra/abseil/abseil-cpp-20230802.1/absl/time/internal/cctz/src/time_zone_format.cc
@@ -19,7 +19,7 @@
 #endif
 
 #if defined(HAS_STRPTIME) && HAS_STRPTIME
-#if !defined(_XOPEN_SOURCE) && !defined(__OpenBSD__)
+#if !defined(_XOPEN_SOURCE) && !defined(__FreeBSD__) && !defined(__OpenBSD__)
 #define _XOPEN_SOURCE 500  // Exposes definitions for SUSv2 (UNIX 98).
 #endif
 #endif
