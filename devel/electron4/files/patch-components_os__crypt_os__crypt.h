--- components/os_crypt/os_crypt.h.orig	2019-03-15 06:37:14 UTC
+++ components/os_crypt/os_crypt.h
@@ -14,7 +14,7 @@
 #include "base/strings/string16.h"
 #include "build/build_config.h"
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS) && defined(UNIT_TEST)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD) && defined(UNIT_TEST)
 class KeyStorageLinux;
 #endif  // defined(OS_LINUX) && !defined(OS_CHROMEOS) && defined(UNIT_TEST)
 
@@ -28,7 +28,7 @@ struct Config;
 // true for Linux, if a password management tool is available.
 class OSCrypt {
  public:
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   // Set the configuration of OSCrypt.
   static void SetConfig(std::unique_ptr<os_crypt::Config> config);
 
@@ -67,7 +67,7 @@ class OSCrypt {
   DISALLOW_IMPLICIT_CONSTRUCTORS(OSCrypt);
 };
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS) && defined(UNIT_TEST)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD) && defined(UNIT_TEST)
 // For unit testing purposes, inject methods to be used.
 // |get_key_storage_mock| provides the desired |KeyStorage| implementation.
 // If the provider returns |nullptr|, a hardcoded password will be used.
