--- electron/shell/browser/api/electron_api_safe_storage.cc.orig	2022-05-18 15:31:32 UTC
+++ electron/shell/browser/api/electron_api_safe_storage.cc
@@ -31,7 +31,7 @@ void SetElectronCryptoReady(bool ready) {
 #endif
 
 bool IsEncryptionAvailable() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Calling IsEncryptionAvailable() before the app is ready results in a crash
   // on Linux.
   // Refs: https://github.com/electron/electron/issues/32206.
