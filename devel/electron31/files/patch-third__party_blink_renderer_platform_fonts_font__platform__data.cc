--- third_party/blink/renderer/platform/fonts/font_platform_data.cc.orig	2024-06-18 21:43:41 UTC
+++ third_party/blink/renderer/platform/fonts/font_platform_data.cc
@@ -49,7 +49,7 @@ namespace {
 namespace blink {
 namespace {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Getting the system font render style takes a significant amount of time on
 // Linux because looking up fonts using fontconfig can be very slow. We fetch
 // the render style for each font family and text size, while it's very
@@ -128,7 +128,7 @@ FontPlatformData::FontPlatformData(sk_sp<SkTypeface> t
   style_ = WebFontRenderStyle::GetDefault();
 #if !BUILDFLAG(IS_WIN)
   WebFontRenderStyle system_style;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   bool override_font_name_and_size =
       base::FeatureList::IsEnabled(kOptimizeLinuxFonts);
 #else
