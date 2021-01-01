--- components/os_crypt/os_crypt.h.orig	2019-09-10 10:42:35 UTC
+++ components/os_crypt/os_crypt.h
@@ -15,9 +15,9 @@
 #include "base/strings/string16.h"
 #include "build/build_config.h"
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 class KeyStorageLinux;
-#endif  // defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#endif  // (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 
 #if defined(OS_MACOSX) && !defined(OS_IOS)
 class PrefRegistrySimple;
@@ -34,13 +34,13 @@ struct Config;
 // true for Linux, if a password management tool is available.
 class OSCrypt {
  public:
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   // Set the configuration of OSCrypt.
   static COMPONENT_EXPORT(OS_CRYPT) void SetConfig(
       std::unique_ptr<os_crypt::Config> config);
-#endif  // defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#endif  // (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 
-#if defined(OS_MACOSX) || (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#if defined(OS_MACOSX) || (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   // On Linux returns true iff the real secret key (not hardcoded one) is
   // available. On MacOS returns true if Keychain is available (for mock
   // Keychain it returns true if not using locked Keychain, false if using
@@ -112,7 +112,7 @@ class OSCrypt {
   DISALLOW_IMPLICIT_CONSTRUCTORS(OSCrypt);
 };
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 // For unit testing purposes, inject methods to be used.
 // |get_key_storage_mock| provides the desired |KeyStorage| implementation.
 // If the provider returns |nullptr|, a hardcoded password will be used.
@@ -127,6 +127,6 @@ void UseMockKeyStorageForTesting(
 // Clears any caching and most lazy initialisations performed by the production
 // code. Should be used after any test which required a password.
 COMPONENT_EXPORT(OS_CRYPT) void ClearCacheForTesting();
-#endif  // defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#endif  // (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 
 #endif  // COMPONENTS_OS_CRYPT_OS_CRYPT_H_
