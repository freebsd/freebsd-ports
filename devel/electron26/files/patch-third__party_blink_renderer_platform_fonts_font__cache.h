--- third_party/blink/renderer/platform/fonts/font_cache.h.orig	2023-08-10 01:48:51 UTC
+++ third_party/blink/renderer/platform/fonts/font_cache.h
@@ -57,7 +57,7 @@
 #include "third_party/skia/include/core/SkFontMgr.h"
 #include "third_party/skia/include/core/SkRefCnt.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "ui/gfx/font_fallback_linux.h"
 #endif
 
@@ -187,7 +187,7 @@ class PLATFORM_EXPORT FontCache final {
   static void PrewarmFamily(const AtomicString& family_name) {}
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // These are needed for calling QueryRenderStyleForStrike, since
   // gfx::GetFontRenderParams makes distinctions based on DSF.
   static float DeviceScaleFactor() { return device_scale_factor_; }
@@ -263,7 +263,7 @@ class PLATFORM_EXPORT FontCache final {
       const char* locale_family_name);
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   static bool GetFontForCharacter(UChar32,
                                   const char* preferred_locale,
                                   gfx::FallbackFontData*);
@@ -344,7 +344,7 @@ class PLATFORM_EXPORT FontCache final {
                                    const FontFaceCreationParams&,
                                    std::string& name);
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   static AtomicString GetFamilyNameForCharacter(SkFontMgr*,
                                                 UChar32,
                                                 const FontDescription&,
@@ -382,7 +382,7 @@ class PLATFORM_EXPORT FontCache final {
   bool is_test_font_mgr_ = false;
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   static float device_scale_factor_;
 #endif
 
