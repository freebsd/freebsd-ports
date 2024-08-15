--- components/password_manager/core/browser/features/password_features.h.orig	2024-06-18 21:43:29 UTC
+++ components/password_manager/core/browser/features/password_features.h
@@ -82,7 +82,7 @@ BASE_DECLARE_FEATURE(kPasswordManualFallbackAvailable)
 // Enables triggering password suggestions through the context menu.
 BASE_DECLARE_FEATURE(kPasswordManualFallbackAvailable);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enables "Needs access to keychain, restart chrome" bubble and banner.
 BASE_DECLARE_FEATURE(kRestartToGainAccessToKeychain);
 #endif  // BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
