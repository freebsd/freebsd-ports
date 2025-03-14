--- components/safe_browsing/core/common/features.cc.orig	2025-01-27 17:37:37 UTC
+++ components/safe_browsing/core/common/features.cc
@@ -256,7 +256,7 @@ BASE_FEATURE(kSafeBrowsingAsyncRealTimeCheck,
 BASE_FEATURE(kSafeBrowsingAsyncRealTimeCheck,
              "SafeBrowsingAsyncRealTimeCheck",
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
