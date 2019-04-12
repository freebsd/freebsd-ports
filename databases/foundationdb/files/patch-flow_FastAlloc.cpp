--- flow/FastAlloc.cpp.orig	2019-04-09 00:11:05 UTC
+++ flow/FastAlloc.cpp
@@ -53,6 +53,9 @@
 #elif defined(__APPLE__)
 #pragma message "init_priority is not supported on this platform; will this be a problem?"
 #define INIT_SEG
+#elif defined(__FreeBSD__)
+#pragma message "init_priority is not supported on this platform; will this be a problem?"
+#define INIT_SEG
 #else
 #error Where am I?
 #endif
