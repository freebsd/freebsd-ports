--- services/catalog/public/cpp/manifest_parsing_util.cc.orig	2019-03-15 06:37:32 UTC
+++ services/catalog/public/cpp/manifest_parsing_util.cc
@@ -17,7 +17,8 @@ bool IsValidPlatformName(const std::string& name) {
          name == Store::kRequiredFilesKey_PlatformValue_Linux ||
          name == Store::kRequiredFilesKey_PlatformValue_MacOSX ||
          name == Store::kRequiredFilesKey_PlatformValue_Android ||
-         name == Store::kRequiredFilesKey_PlatformValue_Fuchsia;
+         name == Store::kRequiredFilesKey_PlatformValue_Fuchsia ||
+         name == Store::kRequiredFilesKey_PlatformValue_FreeBSD;
 }
 
 bool IsCurrentPlatform(const std::string& name) {
@@ -31,6 +32,8 @@ bool IsCurrentPlatform(const std::string& name) {
   return name == Store::kRequiredFilesKey_PlatformValue_Android;
 #elif defined(OS_FUCHSIA)
   return name == Store::kRequiredFilesKey_PlatformValue_Fuchsia;
+#elif defined(OS_BSD)
+  return name == Store::kRequiredFilesKey_PlatformValue_FreeBSD;
 #else
 #error This architecture is not supported.
 #endif
