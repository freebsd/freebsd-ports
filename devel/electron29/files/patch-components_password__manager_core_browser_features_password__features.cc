--- components/password_manager/core/browser/features/password_features.cc.orig	2024-02-21 00:20:41 UTC
+++ components/password_manager/core/browser/features/password_features.cc
@@ -24,7 +24,7 @@ BASE_FEATURE(kClearUndecryptablePasswordsOnSync,
 
 BASE_FEATURE(kClearUndecryptablePasswordsOnSync,
              "ClearUndecryptablePasswordsInSync",
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_IOS)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -104,7 +104,7 @@ BASE_FEATURE(kPasswordManagerLogToTerminal,
              "PasswordManagerLogToTerminal",
              base::FEATURE_DISABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kRestartToGainAccessToKeychain,
              "RestartToGainAccessToKeychain",
              base::FEATURE_DISABLED_BY_DEFAULT);
