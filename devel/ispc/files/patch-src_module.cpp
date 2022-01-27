--- src/module.cpp.orig	2022-01-15 08:35:15 UTC
+++ src/module.cpp
@@ -105,7 +105,7 @@
 #define OCLOC_LIBRARY_NAME "ocloc64.dll"
 #elif defined(_WIN32)
 #define OCLOC_LIBRARY_NAME "ocloc32.dll"
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 #define OCLOC_LIBRARY_NAME "libocloc.so"
 #else
 #error "Unexpected platform"
