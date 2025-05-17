--- third_party/blink/renderer/platform/fonts/font_description.cc.orig	2025-04-22 20:15:27 UTC
+++ third_party/blink/renderer/platform/fonts/font_description.cc
@@ -41,7 +41,7 @@
 #include "third_party/blink/renderer/platform/wtf/text/string_hash.h"
 #include "third_party/blink/renderer/platform/wtf/text/string_hasher.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 #include "third_party/blink/renderer/platform/fonts/font_cache.h"
 #endif
 
@@ -280,7 +280,7 @@ FontCacheKey FontDescription::CacheKey(
       static_cast<unsigned>(fields_.orientation_) << 1 |            // bit 2-3
       static_cast<unsigned>(fields_.subpixel_text_position_);       // bit 1
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   float device_scale_factor_for_key = FontCache::DeviceScaleFactor();
 #else
   float device_scale_factor_for_key = 1.0f;
