--- content/common/features.cc.orig	2026-11-05 12:23:53 UTC
+++ content/common/features.cc
@@ -246,7 +246,7 @@ BASE_FEATURE(kEmbeddingRequiresOptIn, base::FEATURE_DI
 BASE_FEATURE(kEmbeddingRequiresOptIn, base::FEATURE_DISABLED_BY_DEFAULT);
 
 // Enables error reporting for JS errors inside DevTools frontend host
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kEnableDevToolsJsErrorReporting,
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
@@ -309,12 +309,12 @@ BASE_FEATURE(kFocusRenderWidgetHostViewAndroidOnMouseD
 // fetch fonts from the Browser's FontDataService. It is currently scoped to
 // Linux and ChromeOS. See
 // crbug.com/335680565.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const base::FeatureParam<FontDataServiceTypefaceType>::Option
     font_data_service_typeface[] = {
         {FontDataServiceTypefaceType::kFreetype, "Freetype"},
         {FontDataServiceTypefaceType::kFontations, "Fontations"}};
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kFontDataServiceLinux, base::FEATURE_ENABLED_BY_DEFAULT);
 BASE_FEATURE_ENUM_PARAM(FontDataServiceTypefaceType,
                         kFontDataServiceTypefaceType,
@@ -340,11 +340,11 @@ BASE_FEATURE(kFontDataServiceForCSSLocalFonts,
 BASE_FEATURE(kFontDataServiceForCSSLocalFonts,
              base::FEATURE_DISABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 bool IsFontDataServiceEnabled() {
 #if BUILDFLAG(IS_WIN)
   return true;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return base::FeatureList::IsEnabled(features::kFontDataServiceLinux);
 #elif BUILDFLAG(IS_CHROMEOS)
   return base::FeatureList::IsEnabled(features::kFontDataServiceChromeOS);
@@ -856,7 +856,7 @@ BASE_FEATURE(kTouchpadOverscrollHistoryNavigation,
 // is handled at a different level and not through the interpretation of scroll
 // events.
 BASE_FEATURE(kTouchpadOverscrollHistoryNavigation,
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
