--- src/version.h.orig	2021-05-02 14:08:53 UTC
+++ src/version.h
@@ -4,9 +4,7 @@
 #define MINOR_VERSION 12
 #define PATCH_VERSION 2
 
-#define str(s) #s
-#define xstr(s) str(s)
-#define APP_VERSION xstr(MAJOR_VERSION) "." xstr(MINOR_VERSION) "." xstr(PATCH_VERSION)
+#define APP_VERSION "3.12.2"
 
 // If it is defined by the compiler, then it is a nightly build, and in the YYYYMMDD format.
 #ifndef BUILD_VERSION
