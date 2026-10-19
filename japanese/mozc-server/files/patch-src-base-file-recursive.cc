--- src/base/file/recursive.cc.orig	2026-10-17 19:43:44 UTC
+++ src/base/file/recursive.cc
@@ -104,7 +104,7 @@ void UnlinkFileOrLog(const char* path) {
 }  // namespace
 
 #if (defined(__linux__) && !defined(__ANDROID__)) || \
-    (defined(TARGET_OS_OSX) && TARGET_OS_OSX)
+    (defined(TARGET_OS_OSX) && TARGET_OS_OSX) || defined(__FreeBSD__)
 
 absl::Status DeleteRecursively(const absl::string_view path) {
   // fts is not POSIX, but it's available on both Linux and MacOS.
@@ -155,7 +155,7 @@ absl::Status DeleteRecursively(const absl::string_view
   return absl::OkStatus();
 }
 
-#else  // (__linux__ && !__ANDROID__) || TARGET_OS_OSX
+#else  // (__linux__ && !__ANDROID__) || TARGET_OS_OSX || __FreeBSD__
 
 namespace {
 int FtwDelete(const char* path, const struct stat* sb, int typeflag,
@@ -193,7 +193,7 @@ absl::Status DeleteRecursively(const absl::string_view
   return absl::OkStatus();
 }
 
-#endif  // !(__linux__ && !__ANDROID__) || TARGET_OS_OSX)
+#endif  // !(__linux__ && !__ANDROID__) || TARGET_OS_OSX) || __FreeBSD__
 #endif  // !_WIN32
 
 }  // namespace mozc::file
