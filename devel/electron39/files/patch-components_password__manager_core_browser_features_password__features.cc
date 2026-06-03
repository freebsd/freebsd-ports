--- components/password_manager/core/browser/features/password_features.cc.orig	2025-10-21 20:19:54 UTC
+++ components/password_manager/core/browser/features/password_features.cc
@@ -58,7 +58,7 @@ BASE_FEATURE(kClearUndecryptablePasswordsOnSync,
 BASE_FEATURE(kClearUndecryptablePasswordsOnSync,
              "ClearUndecryptablePasswordsInSync",
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_IOS) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -120,7 +120,7 @@ BASE_FEATURE(kPasswordManagerLogToTerminal, base::FEAT
 
 BASE_FEATURE(kPasswordManagerLogToTerminal, base::FEATURE_DISABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kRestartToGainAccessToKeychain,
 #if BUILDFLAG(IS_MAC)
              base::FEATURE_ENABLED_BY_DEFAULT);
