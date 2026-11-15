--- services/network/public/cpp/features.cc.orig	2026-10-19 21:50:55 UTC
+++ services/network/public/cpp/features.cc
@@ -76,7 +76,7 @@ BASE_FEATURE(kDnsOverHttpsUpgrade,
 // Enable usage of hardcoded DoH upgrade mapping for use in automatic mode.
 BASE_FEATURE(kDnsOverHttpsUpgrade,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
