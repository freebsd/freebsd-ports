--- net/base/features.cc.orig	2026-04-28 21:06:17 UTC
+++ net/base/features.cc
@@ -36,7 +36,7 @@ BASE_FEATURE(kAsyncDns,
 
 BASE_FEATURE(kAsyncDns,
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -308,7 +308,7 @@ BASE_FEATURE(kMigrateSessionsOnNetworkChangeV2,
 BASE_FEATURE(kMigrateSessionsOnNetworkChangeV2,
              kMigrateSessionsOnNetworkChangeV2Default);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kAddressTrackerLinuxIsProxied, base::FEATURE_ENABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -427,7 +427,7 @@ BASE_FEATURE(kSimdutfBase64Support,
              base::FEATURE_DISABLED_BY_DEFAULT);
 
 BASE_FEATURE(kSimdutfBase64Support,
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
