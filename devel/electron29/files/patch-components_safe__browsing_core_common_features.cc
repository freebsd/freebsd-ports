--- components/safe_browsing/core/common/features.cc.orig	2024-02-21 00:20:42 UTC
+++ components/safe_browsing/core/common/features.cc
@@ -201,7 +201,7 @@ BASE_FEATURE(kSafeBrowsingSkipSubresources2,
 BASE_FEATURE(kSafeBrowsingSkipSubresources2,
              "SafeBrowsingSkipSubResources2",
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_LACROS)
+    BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
