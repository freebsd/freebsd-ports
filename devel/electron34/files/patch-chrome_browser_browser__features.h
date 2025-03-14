--- chrome/browser/browser_features.h.orig	2025-01-27 17:37:37 UTC
+++ chrome/browser/browser_features.h
@@ -37,7 +37,7 @@ BASE_DECLARE_FEATURE(kCertVerificationNetworkTime);
 BASE_DECLARE_FEATURE(kCertificateTransparencyAskBeforeEnabling);
 BASE_DECLARE_FEATURE(kCertVerificationNetworkTime);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kDbusSecretPortal);
 #endif
 
@@ -111,7 +111,7 @@ BASE_DECLARE_FEATURE(kSandboxExternalProtocolBlockedWa
 BASE_DECLARE_FEATURE(kSandboxExternalProtocolBlocked);
 BASE_DECLARE_FEATURE(kSandboxExternalProtocolBlockedWarning);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kSecretPortalKeyProviderUseForEncryption);
 #endif
 
