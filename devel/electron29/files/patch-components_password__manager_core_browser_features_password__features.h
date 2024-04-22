--- components/password_manager/core/browser/features/password_features.h.orig	2024-02-21 00:20:41 UTC
+++ components/password_manager/core/browser/features/password_features.h
@@ -94,7 +94,7 @@ BASE_DECLARE_FEATURE(kPasswordManagerLogToTerminal);
 // terminal.
 BASE_DECLARE_FEATURE(kPasswordManagerLogToTerminal);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enables "Needs access to keychain, restart chrome" bubble and banner.
 BASE_DECLARE_FEATURE(kRestartToGainAccessToKeychain);
 #endif  // BUILDFLAG(IS_MAC)
