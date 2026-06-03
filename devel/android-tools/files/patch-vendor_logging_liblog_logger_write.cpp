--- vendor/logging/liblog/logger_write.cpp	2024-08-29 19:46:57.000000000 +0200
+++ vendor/logging/liblog/logger_write.cpp	2026-03-21 13:49:27.807366000 +0100
@@ -119,8 +119,8 @@
 #endif
 }
 
-// BSD-based systems like Android/macOS have getprogname(). Others need us to provide one.
-#if !defined(__APPLE__) && !defined(__BIONIC__)
+// BSD-based systems like Android/macOS/FreeBSD have getprogname(). Others need us to provide one.
+#if !defined(__APPLE__) && !defined(__BIONIC__) && !defined(__FreeBSD__)
 static const char* getprogname() {
 #ifdef _WIN32
   static bool first = true;
