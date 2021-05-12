--- third_party/blink/renderer/platform/fonts/font_cache.cc.orig	2021-01-07 00:36:43 UTC
+++ third_party/blink/renderer/platform/fonts/font_cache.cc
@@ -80,7 +80,7 @@ const char kColorEmojiLocale[] = "und-Zsye";
 
 SkFontMgr* FontCache::static_font_manager_ = nullptr;
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 float FontCache::device_scale_factor_ = 1.0;
 #endif
 
@@ -120,7 +120,7 @@ FontCache::FontCache()
 FontPlatformData* FontCache::SystemFontPlatformData(
     const FontDescription& font_description) {
   const AtomicString& family = FontCache::SystemFontFamily();
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_FUCHSIA) || defined(OS_BSD)
   if (family.IsEmpty() || family == font_family_names::kSystemUi)
     return nullptr;
 #else
