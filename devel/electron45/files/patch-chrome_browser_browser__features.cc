--- chrome/browser/browser_features.cc.orig	2026-10-19 21:50:55 UTC
+++ chrome/browser/browser_features.cc
@@ -63,7 +63,7 @@ BASE_FEATURE(kClearUserDataUponProfileDestruction,
 BASE_FEATURE(kClearUserDataUponProfileDestruction,
              base::FEATURE_ENABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enables usage of os_crypt_async::SecretPortalKeyProvider.  Once
 // `kSecretPortalKeyProviderUseForEncryption` is enabled, this flag cannot be
 // disabled without losing data.
@@ -73,7 +73,7 @@ BASE_FEATURE(kDestroyProfileOnBrowserClose,
 // Destroy profiles when their last browser window is closed, instead of when
 // the browser exits.
 BASE_FEATURE(kDestroyProfileOnBrowserClose,
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -155,7 +155,7 @@ BASE_FEATURE(kSandboxExternalProtocolBlockedWarning,
 BASE_FEATURE(kSandboxExternalProtocolBlockedWarning,
              base::FEATURE_ENABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // If true, encrypt new data with the key provided by SecretPortalKeyProvider.
 // Otherwise, it will only decrypt existing data.
 BASE_FEATURE(kSecretPortalKeyProviderUseForEncryption,
