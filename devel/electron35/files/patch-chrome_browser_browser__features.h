--- chrome/browser/browser_features.h.orig	2025-03-24 20:50:14 UTC
+++ chrome/browser/browser_features.h
@@ -39,7 +39,7 @@ BASE_DECLARE_FEATURE(kContentUsesBrowserThemeColorMode
 
 BASE_DECLARE_FEATURE(kContentUsesBrowserThemeColorMode);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kDbusSecretPortal);
 BASE_DECLARE_FEATURE(kUseFreedesktopSecretKeyProvider);
 #endif
@@ -101,7 +101,7 @@ BASE_DECLARE_FEATURE(kSandboxExternalProtocolBlockedWa
 BASE_DECLARE_FEATURE(kSandboxExternalProtocolBlocked);
 BASE_DECLARE_FEATURE(kSandboxExternalProtocolBlockedWarning);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kSecretPortalKeyProviderUseForEncryption);
 BASE_DECLARE_FEATURE(kUseFreedesktopSecretKeyProviderForEncryption);
 #endif
