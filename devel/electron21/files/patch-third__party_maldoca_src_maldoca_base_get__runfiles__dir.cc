--- third_party/maldoca/src/maldoca/base/get_runfiles_dir.cc.orig	2022-02-07 13:39:41 UTC
+++ third_party/maldoca/src/maldoca/base/get_runfiles_dir.cc
@@ -24,11 +24,6 @@
 #error "__APPLE__ not supported."
 #endif
 
-#if defined(__FreeBSD__)
-// TODO(#110) FreeBSD-specific headers.
-#error "__FreeBSD__ not supported."
-#endif
-
 #if defined(_WIN32)
 #include <windows.h>
 #define PATH_MAX MAX_PATH
@@ -50,8 +45,6 @@ std::string GetExecutablePath() {
   char exe_path[PATH_MAX] = {0};
 #ifdef __APPLE__
 #error "__APPLE__ not supported.";
-#elif defined(__FreeBSD__)
-#error "__FreeBSD__ not supported.";
 #elif defined(_WIN32)
   HMODULE hModule = GetModuleHandleW(NULL);
   WCHAR wc_file_path[MAX_PATH] = {0};
@@ -97,8 +90,6 @@ std::string GetExecutablePath() {
 absl::Status IsDirectory(const std::string& name) {
 #ifdef __APPLE__
 #error "__APPLE__ not supported.";
-#elif defined(__FreeBSD__)
-#error "__FreeBSD__ not supported.";
 #else
   struct stat sbuf;
   if (stat(name.c_str(), &sbuf) != 0) {
