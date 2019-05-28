--- services/catalog/store.cc.orig	2019-03-15 06:37:32 UTC
+++ services/catalog/store.cc
@@ -36,5 +36,7 @@ const char Store::kRequiredFilesKey_PlatformValue_MacO
 const char Store::kRequiredFilesKey_PlatformValue_Android[] = "android";
 // static
 const char Store::kRequiredFilesKey_PlatformValue_Fuchsia[] = "fuchsia";
+// static
+const char Store::kRequiredFilesKey_PlatformValue_FreeBSD[] = "freebsd";
 
 }  // namespace catalog
