--- services/network/public/cpp/features.cc.orig	2023-10-19 19:58:30 UTC
+++ services/network/public/cpp/features.cc
@@ -383,7 +383,7 @@ BASE_FEATURE(kPrivateNetworkAccessPermissionPrompt,
 // that can be adequately sandboxed.
 BASE_FEATURE(kOutOfProcessSystemDnsResolution,
              "OutOfProcessSystemDnsResolution",
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
