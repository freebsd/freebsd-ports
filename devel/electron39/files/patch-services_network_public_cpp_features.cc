--- services/network/public/cpp/features.cc.orig	2025-10-21 20:19:54 UTC
+++ services/network/public/cpp/features.cc
@@ -93,7 +93,7 @@ BASE_FEATURE(kDnsOverHttpsUpgrade,
 // Enable usage of hardcoded DoH upgrade mapping for use in automatic mode.
 BASE_FEATURE(kDnsOverHttpsUpgrade,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -345,7 +345,7 @@ BASE_FEATURE(kDocumentIsolationPolicy,
 // https://github.com/WICG/document-isolation-policy
 BASE_FEATURE(kDocumentIsolationPolicy,
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
