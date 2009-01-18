--- src/main.cxx.orig	2009-01-17 14:54:56.000000000 -0500
+++ src/main.cxx	2009-01-17 14:55:05.000000000 -0500
@@ -723,7 +723,7 @@
 
 void set_platform_ui(void)
 {
-#if defined (__linux__)
+#if defined (__linux__) || defined(__FreeBSD__)
        FL_NORMAL_SIZE = 12;
 #elif defined(__APPLE__)
        FL_NORMAL_SIZE = 12;
