--- src/bthread/sys_futex.cpp.orig	2026-02-23 02:11:29 UTC
+++ src/bthread/sys_futex.cpp
@@ -25,7 +25,7 @@
 #include <pthread.h>
 #include <unordered_map>
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
 
 namespace bthread {
 
