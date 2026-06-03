--- third_party/blink/common/features.cc.orig	2025-08-26 20:49:50 UTC
+++ third_party/blink/common/features.cc
@@ -683,7 +683,7 @@ BASE_FEATURE(kDirectCompositorThreadIpc,
 
 BASE_FEATURE(kDirectCompositorThreadIpc,
              "DirectCompositorThreadIpc",
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
