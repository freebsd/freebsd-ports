--- net/base/features.cc.orig	2025-06-30 07:04:30 UTC
+++ net/base/features.cc
@@ -31,7 +31,7 @@ BASE_FEATURE(kAsyncDns,
 BASE_FEATURE(kAsyncDns,
              "AsyncDns",
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
