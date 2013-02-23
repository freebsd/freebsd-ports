--- higan/nall/file.hpp.orig	2013-01-14 13:27:28.000000000 -0500
+++ higan/nall/file.hpp	2013-02-21 14:05:00.000000000 -0500
@@ -218,8 +218,8 @@
 
     static bool exists(const string &filename) {
       #if !defined(_WIN32)
-      struct stat64 data;
-      return stat64(filename, &data) == 0;
+      struct stat data;
+      return stat(filename, &data) == 0;
       #else
       struct __stat64 data;
       return _wstat64(utf16_t(filename), &data) == 0;
@@ -228,8 +228,8 @@
 
     static uintmax_t size(const string &filename) {
       #if !defined(_WIN32)
-      struct stat64 data;
-      stat64(filename, &data);
+      struct stat data;
+      stat(filename, &data);
       #else
       struct __stat64 data;
       _wstat64(utf16_t(filename), &data);
@@ -239,8 +239,8 @@
 
     static time_t timestamp(const string &filename, file::time mode = file::time::create) {
       #if !defined(_WIN32)
-      struct stat64 data;
-      stat64(filename, &data);
+      struct stat data;
+      stat(filename, &data);
       #else
       struct __stat64 data;
       _wstat64(utf16_t(filename), &data);
--- ananke/nall/file.hpp.orig	2013-01-11 13:26:29.000000000 -0500
+++ ananke/nall/file.hpp	2013-02-21 14:06:08.000000000 -0500
@@ -218,8 +218,8 @@
 
     static bool exists(const string &filename) {
       #if !defined(_WIN32)
-      struct stat64 data;
-      return stat64(filename, &data) == 0;
+      struct stat data;
+      return stat(filename, &data) == 0;
       #else
       struct __stat64 data;
       return _wstat64(utf16_t(filename), &data) == 0;
@@ -228,8 +228,8 @@
 
     static uintmax_t size(const string &filename) {
       #if !defined(_WIN32)
-      struct stat64 data;
-      stat64(filename, &data);
+      struct stat data;
+      stat(filename, &data);
       #else
       struct __stat64 data;
       _wstat64(utf16_t(filename), &data);
@@ -239,8 +239,8 @@
 
     static time_t timestamp(const string &filename, file::time mode = file::time::create) {
       #if !defined(_WIN32)
-      struct stat64 data;
-      stat64(filename, &data);
+      struct stat data;
+      stat(filename, &data);
       #else
       struct __stat64 data;
       _wstat64(utf16_t(filename), &data);
