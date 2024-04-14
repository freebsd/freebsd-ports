--- components/signin/public/base/signin_switches.cc.orig	2024-02-21 00:20:42 UTC
+++ components/signin/public/base/signin_switches.cc
@@ -104,7 +104,7 @@ BASE_FEATURE(kUnoDesktop, "UnoDesktop", base::FEATURE_
 BASE_FEATURE(kUnoDesktop, "UnoDesktop", base::FEATURE_DISABLED_BY_DEFAULT);
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kMinorModeRestrictionsForHistorySyncOptIn,
              "MinorModeRestrictionsForHistorySyncOptIn",
              base::FEATURE_DISABLED_BY_DEFAULT);
