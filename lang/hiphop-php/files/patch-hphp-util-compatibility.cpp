--- hphp/util/compatibility.cpp.orig	2013-07-21 12:48:24.829495815 +0200
+++ hphp/util/compatibility.cpp	2013-07-21 12:48:45.364579480 +0200
@@ -20,7 +20,7 @@
 namespace HPHP {
 ///////////////////////////////////////////////////////////////////////////////
 
-#if defined(__APPLE__)
+#if defined(__APPLE__) || defined(__FreeBSD__)
 char *strndup(const char* str, size_t len) {
   size_t str_len = strlen(str);
   if (len < str_len) {
