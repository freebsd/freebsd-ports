--- electron/shell/browser/api/electron_api_safe_storage.cc.orig	2023-01-24 16:58:16 UTC
+++ electron/shell/browser/api/electron_api_safe_storage.cc
@@ -29,7 +29,7 @@ void SetElectronCryptoReady(bool ready) {
 #endif
 
 bool IsEncryptionAvailable() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Calling IsEncryptionAvailable() before the app is ready results in a crash
   // on Linux.
   // Refs: https://github.com/electron/electron/issues/32206.
