--- third_party/blink/renderer/core/exported/web_view_impl.cc.orig	2022-05-13 07:19:54 UTC
+++ third_party/blink/renderer/core/exported/web_view_impl.cc
@@ -403,7 +403,7 @@ SkFontHinting RendererPreferencesToSkiaHinting(
     const blink::RendererPreferences& prefs) {
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   if (!prefs.should_antialias_text) {
     // When anti-aliasing is off, GTK maps all non-zero hinting settings to
     // 'Normal' hinting so we do the same. Otherwise, folks who have 'Slight'
@@ -3172,7 +3172,7 @@ void WebViewImpl::UpdateFontRenderingFromRendererPrefs
       renderer_preferences_.use_subpixel_positioning);
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
-#if (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) && !defined(OS_ANDROID)
+#if (defined(OS_LINUX) || defined(OS_BSD) || BUILDFLAG(IS_CHROMEOS_LACROS)) && !defined(OS_ANDROID)
   if (!renderer_preferences_.system_font_family_name.empty()) {
     WebFontRenderStyle::SetSystemFontFamily(blink::WebString::FromUTF8(
         renderer_preferences_.system_font_family_name));
