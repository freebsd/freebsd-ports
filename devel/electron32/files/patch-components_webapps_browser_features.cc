--- components/webapps/browser/features.cc.orig	2024-08-14 20:54:58 UTC
+++ components/webapps/browser/features.cc
@@ -59,7 +59,7 @@ BASE_FEATURE(kWebAppsEnableMLModelForPromotion,
 BASE_FEATURE(kWebAppsEnableMLModelForPromotion,
              "WebAppsEnableMLModelForPromotion",
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
