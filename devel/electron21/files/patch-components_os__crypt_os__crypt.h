--- components/os_crypt/os_crypt.h.orig	2022-07-22 17:30:31 UTC
+++ components/os_crypt/os_crypt.h
@@ -15,7 +15,7 @@
 #include "build/build_config.h"
 #include "build/chromecast_buildflags.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 class KeyStorageLinux;
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -24,7 +24,7 @@ class PrefRegistrySimple;
 class PrefService;
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_APPLE)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_BSD)
 namespace crypto {
 class SymmetricKey;
 }
@@ -37,7 +37,7 @@ struct Config;
 // Temporary interface due to OSCrypt refactor. See OSCryptImpl for descriptions
 // of what each function does.
 namespace OSCrypt {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(OS_CRYPT)
 void SetConfig(std::unique_ptr<os_crypt::Config> config);
 #endif  // BUILDFLAG(IS_LINUX)
@@ -82,7 +82,7 @@ COMPONENT_EXPORT(OS_CRYPT) void UseMockKeyForTesting(b
 COMPONENT_EXPORT(OS_CRYPT) void SetLegacyEncryptionForTesting(bool legacy);
 COMPONENT_EXPORT(OS_CRYPT) void ResetStateForTesting();
 #endif  // BUILDFLAG(IS_WIN)
-#if (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CASTOS))
+#if (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CASTOS)) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(OS_CRYPT)
 void UseMockKeyStorageForTesting(
     base::OnceCallback<std::unique_ptr<KeyStorageLinux>()>
@@ -109,7 +109,7 @@ class COMPONENT_EXPORT(OS_CRYPT) OSCryptImpl {
   // Returns singleton instance of OSCryptImpl.
   static OSCryptImpl* GetInstance();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Set the configuration of OSCryptImpl.
   // This method, or SetRawEncryptionKey(), must be called before using
   // EncryptString() and DecryptString().
@@ -201,7 +201,7 @@ class COMPONENT_EXPORT(OS_CRYPT) OSCryptImpl {
   void ResetStateForTesting();
 #endif
 
-#if (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CASTOS))
+#if (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CASTOS)) || BUILDFLAG(IS_BSD)
   // For unit testing purposes, inject methods to be used.
   // |storage_provider_factory| provides the desired |KeyStorage|
   // implementation. If the provider returns |nullptr|, a hardcoded password
@@ -226,13 +226,13 @@ class COMPONENT_EXPORT(OS_CRYPT) OSCryptImpl {
   crypto::SymmetricKey* GetEncryptionKey();
 #endif  // BUILDFLAG(IS_APPLE)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_APPLE)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_BSD)
   // This lock is used to make the GetEncryptionKey and
   // GetRawEncryptionKey methods thread-safe.
   static base::Lock& GetLock();
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_APPLE)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Create the KeyStorage. Will be null if no service is found. A Config must
   // be set before every call to this method.
   std::unique_ptr<KeyStorageLinux> CreateKeyStorage();
