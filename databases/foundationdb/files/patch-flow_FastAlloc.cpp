--- flow/FastAlloc.cpp.orig	2018-04-22 14:45:22 UTC
+++ flow/FastAlloc.cpp
@@ -51,6 +51,9 @@
 #elif defined(__APPLE__)
 #pragma message "init_priority is not supported on this platform; will this be a problem?"
 #define INIT_SEG
+#elif defined(__FreeBSD__)
+#pragma message "init_priority is not supported on this platform; will this be a problem?"
+#define INIT_SEG
 #else
 #error Where am I?
 #endif
