--- bsnes/nall/file.hpp.orig	2012-03-06 14:03:53.000000000 -0500
+++ bsnes/nall/file.hpp	2012-04-16 23:42:33.000000000 -0400
@@ -160,8 +160,8 @@
 
     static bool exists(const string &filename) {
       #if !defined(_WIN32)
-      struct stat64 data;
-      return stat64(filename, &data) == 0;
+      struct stat data;
+      return stat(filename, &data) == 0;
       #else
       struct __stat64 data;
       return _wstat64(utf16_t(filename), &data) == 0;
@@ -170,8 +170,8 @@
 
     static uintmax_t size(const string &filename) {
       #if !defined(_WIN32)
-      struct stat64 data;
-      stat64(filename, &data);
+      struct stat data;
+      stat(filename, &data);
       #else
       struct __stat64 data;
       _wstat64(utf16_t(filename), &data);
@@ -181,8 +181,8 @@
 
     static time_t timestamp(const string &filename, file::time mode = file::time::create) {
       #if !defined(_WIN32)
-      struct stat64 data;
-      stat64(filename, &data);
+      struct stat data;
+      stat(filename, &data);
       #else
       struct __stat64 data;
       _wstat64(utf16_t(filename), &data);
--- purify/nall/file.hpp.orig	2012-04-23 02:11:07.000000000 -0400
+++ purify/nall/file.hpp	2012-05-06 22:54:42.000000000 -0400
@@ -160,8 +160,8 @@
 
     static bool exists(const string &filename) {
       #if !defined(_WIN32)
-      struct stat64 data;
-      return stat64(filename, &data) == 0;
+      struct stat data;
+      return stat(filename, &data) == 0;
       #else
       struct __stat64 data;
       return _wstat64(utf16_t(filename), &data) == 0;
@@ -170,8 +170,8 @@
 
     static uintmax_t size(const string &filename) {
       #if !defined(_WIN32)
-      struct stat64 data;
-      stat64(filename, &data);
+      struct stat data;
+      stat(filename, &data);
       #else
       struct __stat64 data;
       _wstat64(utf16_t(filename), &data);
@@ -181,8 +181,8 @@
 
     static time_t timestamp(const string &filename, file::time mode = file::time::create) {
       #if !defined(_WIN32)
-      struct stat64 data;
-      stat64(filename, &data);
+      struct stat data;
+      stat(filename, &data);
       #else
       struct __stat64 data;
       _wstat64(utf16_t(filename), &data);
