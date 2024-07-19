--- components/safe_browsing/core/common/features.cc.orig	2024-06-18 21:43:30 UTC
+++ components/safe_browsing/core/common/features.cc
@@ -160,7 +160,7 @@ BASE_FEATURE(kHashPrefixRealTimeLookups,
 BASE_FEATURE(kHashPrefixRealTimeLookups,
              "SafeBrowsingHashPrefixRealTimeLookups",
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
