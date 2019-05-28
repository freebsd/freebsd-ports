--- services/catalog/store.h.orig	2019-03-15 06:37:32 UTC
+++ services/catalog/store.h
@@ -36,6 +36,7 @@ class Store {
   static const char kRequiredFilesKey_PlatformValue_MacOSX[];
   static const char kRequiredFilesKey_PlatformValue_Android[];
   static const char kRequiredFilesKey_PlatformValue_Fuchsia[];
+  static const char kRequiredFilesKey_PlatformValue_FreeBSD[];
 };
 
 }  // namespace catalog
