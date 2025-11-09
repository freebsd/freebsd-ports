--- content/common/features.cc.orig	2025-11-02 19:17:58 UTC
+++ content/common/features.cc
@@ -144,7 +144,7 @@ BASE_FEATURE(kEmbeddingRequiresOptIn, base::FEATURE_DI
 BASE_FEATURE(kEmbeddingRequiresOptIn, base::FEATURE_DISABLED_BY_DEFAULT);
 
 // Enables error reporting for JS errors inside DevTools frontend host
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kEnableDevToolsJsErrorReporting,
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
