--- third_party/blink/common/features.cc.orig	2025-10-21 20:19:54 UTC
+++ third_party/blink/common/features.cc
@@ -572,7 +572,7 @@ BASE_FEATURE(kDirectCompositorThreadIpc,
 BASE_FEATURE(kDevToolsImprovedNetworkError, base::FEATURE_DISABLED_BY_DEFAULT);
 
 BASE_FEATURE(kDirectCompositorThreadIpc,
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
