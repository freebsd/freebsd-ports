--- vendor/libbase/logging.cpp	2024-08-29 19:46:57.000000000 +0200
+++ vendor/libbase/logging.cpp	2026-03-21 13:49:23.603723000 +0100
@@ -26,7 +26,7 @@
 #include <time.h>
 
 // For getprogname(3) or program_invocation_short_name.
-#if defined(__ANDROID__) || defined(__APPLE__)
+#if defined(__ANDROID__) || defined(__APPLE__) || defined(__FreeBSD__)
 #include <stdlib.h>
 #elif defined(__GLIBC__)
 #include <errno.h>
@@ -61,8 +61,8 @@
 namespace android {
 namespace base {
 
-// BSD-based systems like Android/macOS have getprogname(). Others need us to provide one.
-#if !defined(__APPLE__) && !defined(__BIONIC__)
+// BSD-based systems like Android/macOS/FreeBSD have getprogname(). Others need us to provide one.
+#if !defined(__APPLE__) && !defined(__BIONIC__) && !defined(__FreeBSD__)
 static const char* getprogname() {
 #ifdef _WIN32
   static bool first = true;
