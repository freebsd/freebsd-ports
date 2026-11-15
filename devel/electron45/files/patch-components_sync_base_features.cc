--- components/sync/base/features.cc.orig	2026-10-19 21:50:55 UTC
+++ components/sync/base/features.cc
@@ -81,7 +81,7 @@ BASE_FEATURE(kReplaceSyncPromosWithSigninPromosNewSign
 );
 
 BASE_FEATURE(kReplaceSyncPromosWithSigninPromosNewSignin,
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
