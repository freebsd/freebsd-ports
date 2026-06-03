--- components/password_manager/core/browser/features/password_features.h.orig	2026-03-13 16:54:03 UTC
+++ components/password_manager/core/browser/features/password_features.h
@@ -164,7 +164,7 @@ BASE_DECLARE_FEATURE(kReduceRequirementsForPasswordCha
 // control locale/country server side.
 BASE_DECLARE_FEATURE(kReduceRequirementsForPasswordChange);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enables "Needs access to keychain, restart chrome" bubble and banner.
 BASE_DECLARE_FEATURE(kRestartToGainAccessToKeychain);
 #endif  // BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
