--- components/os_crypt/sync/os_crypt.h.orig	2026-09-01 23:50:56 UTC
+++ components/os_crypt/sync/os_crypt.h
@@ -25,9 +25,9 @@ class KeychainV2;
 }
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 class KeyStorageLinux;
-#endif  // BUILDFLAG(IS_LINUX)
+#endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 #if BUILDFLAG(IS_WIN)
 class PrefRegistrySimple;
@@ -41,10 +41,10 @@ namespace OSCrypt {
 // Temporary interface due to OSCrypt refactor. See OSCryptImpl for descriptions
 // of what each function does.
 namespace OSCrypt {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(OS_CRYPT)
 void SetConfig(std::unique_ptr<os_crypt::Config> config);
-#endif  // BUILDFLAG(IS_LINUX)
+#endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(OS_CRYPT) bool IsEncryptionAvailable();
 COMPONENT_EXPORT(OS_CRYPT)
 bool EncryptString16(const std::u16string& plaintext, std::string* ciphertext);
@@ -88,7 +88,7 @@ COMPONENT_EXPORT(OS_CRYPT) void ResetStateForTesting()
 COMPONENT_EXPORT(OS_CRYPT) void SetLegacyEncryptionForTesting(bool legacy);
 COMPONENT_EXPORT(OS_CRYPT) void ResetStateForTesting();
 #endif  // BUILDFLAG(IS_WIN)
-#if (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CASTOS))
+#if ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !BUILDFLAG(IS_CASTOS))
 COMPONENT_EXPORT(OS_CRYPT)
 void UseMockKeyStorageForTesting(
     base::OnceCallback<std::unique_ptr<KeyStorageLinux>()>
@@ -96,13 +96,13 @@ void SetEncryptionPasswordForTesting(const std::string
 COMPONENT_EXPORT(OS_CRYPT) void ClearCacheForTesting();
 COMPONENT_EXPORT(OS_CRYPT)
 void SetEncryptionPasswordForTesting(const std::string& password);
-#endif  // (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CASTOS))
+#endif  // ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !BUILDFLAG(IS_CASTOS))
 #if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_APPLE) &&         \
-        !(BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CASTOS)) || \
+        !((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !BUILDFLAG(IS_CASTOS)) || \
     BUILDFLAG(IS_FUCHSIA)
 COMPONENT_EXPORT(OS_CRYPT)
 void SetEncryptionAvailableForTesting(std::optional<bool> available);
-#endif  // BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_APPLE) && !(BUILDFLAG(IS_LINUX)
+#endif  // BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_APPLE) && !((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
         // && !BUILDFLAG(IS_CASTOS)) || BUILDFLAG(IS_FUCHSIA)
 }  // namespace OSCrypt
 
@@ -122,12 +122,12 @@ class COMPONENT_EXPORT(OS_CRYPT) OSCryptImpl {
   // Returns singleton instance of OSCryptImpl.
   static OSCryptImpl* GetInstance();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Set the configuration of OSCryptImpl.
   // This method, or SetRawEncryptionKey(), must be called before using
   // EncryptString() and DecryptString().
   void SetConfig(std::unique_ptr<os_crypt::Config> config);
-#endif  // BUILDFLAG(IS_LINUX)
+#endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
   // In production code:
   // - On Linux, returns true iff the real secret key (not hardcoded one) is
@@ -214,7 +214,7 @@ class COMPONENT_EXPORT(OS_CRYPT) OSCryptImpl {
   void ResetStateForTesting();
 #endif
 
-#if (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CASTOS))
+#if ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !BUILDFLAG(IS_CASTOS))
   // For unit testing purposes, inject methods to be used.
   // |storage_provider_factory| provides the desired |KeyStorage|
   // implementation. If the provider returns |nullptr|, a hardcoded password
@@ -230,7 +230,7 @@ class COMPONENT_EXPORT(OS_CRYPT) OSCryptImpl {
 
   // Sets the password with which the encryption key is derived, e.g. "peanuts".
   void SetEncryptionPasswordForTesting(const std::string& password);
-#endif  // (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CASTOS))
+#endif  // ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !BUILDFLAG(IS_CASTOS))
  private:
 #if BUILDFLAG(IS_APPLE)
   // Return the keychain to use for accessing the encryption key.
@@ -241,13 +241,13 @@ class COMPONENT_EXPORT(OS_CRYPT) OSCryptImpl {
   bool DeriveKey();
 #endif  // BUILDFLAG(IS_APPLE)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_APPLE)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_BSD)
   // This lock is used to make the GetEncryptionKey and
   // GetRawEncryptionKey methods thread-safe.
   static base::Lock& GetLock();
-#endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_APPLE)
+#endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_BSD)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   static constexpr size_t kDerivedKeyBytes = 16;
 
   crypto::SubtlePassKey MakeCryptoPassKey();
@@ -276,7 +276,7 @@ class COMPONENT_EXPORT(OS_CRYPT) OSCryptImpl {
 
   base::OnceCallback<std::unique_ptr<KeyStorageLinux>()>
       storage_provider_factory_for_testing_;
-#endif  // BUILDFLAG(IS_LINUX)
+#endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 #if BUILDFLAG(IS_WIN)
   // Use mock key instead of a real encryption key. Used for testing.
