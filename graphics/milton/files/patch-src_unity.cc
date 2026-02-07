--- src/unity.cc.orig	2019-03-15 04:11:43 UTC
+++ src/unity.cc
@@ -18,7 +18,7 @@
 
 #if defined(_WIN32)
     #include "platform_windows.cc"
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
     #include "platform_unix.cc"
     #include "platform_linux.cc"
 #elif defined(__MACH__)
