--- clickhouse/base/platform.h.orig	2025-09-20 19:59:03 UTC
+++ clickhouse/base/platform.h
@@ -2,6 +2,8 @@
 
 #if defined(__linux__)
 #   define _linux_
+#elif defined(__FreeBSD__)
+#   define _freebsd_
 #elif defined(_WIN64)
 #   define _win64_
 #   define _win32_
@@ -20,7 +22,7 @@
 #   define WIN32_LEAN_AND_MEAN 1  // don't include too much header automatically
 #endif
 
-#if defined(_linux_) || defined (_darwin_)
+#if defined(_linux_) || defined (_darwin_) || defined(_freebsd_)
 #   define _unix_
 #endif
 
