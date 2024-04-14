--- third_party/blink/renderer/platform/fonts/font_cache.cc.orig	2024-02-21 00:20:54 UTC
+++ third_party/blink/renderer/platform/fonts/font_cache.cc
@@ -73,7 +73,7 @@ SkFontMgr* FontCache::static_font_manager_ = nullptr;
 
 SkFontMgr* FontCache::static_font_manager_ = nullptr;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 float FontCache::device_scale_factor_ = 1.0;
 #endif
 
@@ -124,7 +124,7 @@ FontPlatformData* FontCache::SystemFontPlatformData(
     const FontDescription& font_description) {
   const AtomicString& family = FontCache::SystemFontFamily();
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || \
-    BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
   if (family.empty() || family == font_family_names::kSystemUi)
     return nullptr;
 #else
