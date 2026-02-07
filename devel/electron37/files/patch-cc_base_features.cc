--- cc/base/features.cc.orig	2025-06-30 07:04:30 UTC
+++ cc/base/features.cc
@@ -52,7 +52,7 @@ BASE_FEATURE(kUseDMSAAForTiles,
 // be using a separate flag to control the launch on GL.
 BASE_FEATURE(kUseDMSAAForTiles,
              "UseDMSAAForTiles",
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
