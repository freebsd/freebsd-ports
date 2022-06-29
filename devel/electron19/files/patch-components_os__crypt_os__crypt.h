--- components/os_crypt/os_crypt.h.orig	2022-05-25 04:00:57 UTC
+++ components/os_crypt/os_crypt.h
@@ -14,7 +14,7 @@
 #include "build/build_config.h"
 #include "build/chromecast_buildflags.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 class KeyStorageLinux;
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -30,7 +30,7 @@ struct Config;
 // Temporary interface due to OSCrypt refactor. See OSCryptImpl for descriptions
 // of what each function does.
 namespace OSCrypt {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(OS_CRYPT)
 void SetConfig(std::unique_ptr<os_crypt::Config> config);
 #endif  // BUILDFLAG(IS_LINUX)
@@ -75,7 +75,7 @@ COMPONENT_EXPORT(OS_CRYPT) void UseMockKeyForTesting(b
 COMPONENT_EXPORT(OS_CRYPT) void SetLegacyEncryptionForTesting(bool legacy);
 COMPONENT_EXPORT(OS_CRYPT) void ResetStateForTesting();
 #endif  // BUILDFLAG(IS_WIN)
-#if (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMECAST))
+#if ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !BUILDFLAG(IS_CHROMECAST))
 COMPONENT_EXPORT(OS_CRYPT)
 void UseMockKeyStorageForTesting(
     std::unique_ptr<KeyStorageLinux> (*get_key_storage_mock)());
@@ -95,7 +95,7 @@ class OSCryptImpl {
   OSCryptImpl(const OSCryptImpl&) = delete;
   OSCryptImpl& operator=(const OSCryptImpl&) = delete;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Set the configuration of OSCryptImpl.
   // This method, or SetRawEncryptionKey(), must be called before using
   // EncryptString() and DecryptString().
@@ -200,7 +200,7 @@ class OSCryptImpl {
   static void ResetStateForTesting();
 #endif
 
-#if (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMECAST))
+#if ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !BUILDFLAG(IS_CHROMECAST))
   // For unit testing purposes, inject methods to be used.
   // |get_key_storage_mock| provides the desired |KeyStorage| implementation.
   // If the provider returns |nullptr|, a hardcoded password will be used.
