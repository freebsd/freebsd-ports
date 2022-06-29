--- third_party/blink/renderer/platform/fonts/font_cache.cc.orig	2022-05-25 04:01:09 UTC
+++ third_party/blink/renderer/platform/fonts/font_cache.cc
@@ -75,7 +75,7 @@ extern const char kNotoColorEmojiCompat[] = "Noto Colo
 
 SkFontMgr* FontCache::static_font_manager_ = nullptr;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 float FontCache::device_scale_factor_ = 1.0;
 #endif
 
@@ -120,7 +120,7 @@ FontCache::~FontCache() = default;
 FontPlatformData* FontCache::SystemFontPlatformData(
     const FontDescription& font_description) {
   const AtomicString& family = FontCache::SystemFontFamily();
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   if (family.IsEmpty() || family == font_family_names::kSystemUi)
     return nullptr;
 #else
