--- vendor/libbase/include/android-base/off64_t.h	2024-08-29 19:46:57.000000000 +0200
+++ vendor/libbase/include/android-base/off64_t.h	2026-03-21 13:49:10.156714000 +0100
@@ -16,7 +16,7 @@
 
 #pragma once
 
-#if defined(__APPLE__)
-/** Mac OS has always had a 64-bit off_t, so it doesn't have off64_t. */
+#if defined(__APPLE__) || defined(__FreeBSD__)
+/** Mac OS and FreeBSD have always had a 64-bit off_t, so they don't have off64_t. */
 typedef off_t off64_t;
 #endif
