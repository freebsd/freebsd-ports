--- ui/gfx/font_render_params.h.orig	2021-04-14 01:09:39 UTC
+++ ui/gfx/font_render_params.h
@@ -109,7 +109,7 @@ GFX_EXPORT FontRenderParams GetFontRenderParams(
     const FontRenderParamsQuery& query,
     std::string* family_out);
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 // Clears GetFontRenderParams()'s cache. Intended to be called by tests that are
 // changing Fontconfig's configuration.
 GFX_EXPORT void ClearFontRenderParamsCacheForTest();
@@ -118,7 +118,7 @@ GFX_EXPORT void ClearFontRenderParamsCacheForTest();
 // Gets the device scale factor to query the FontRenderParams.
 GFX_EXPORT float GetFontRenderParamsDeviceScaleFactor();
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_ANDROID) || defined(OS_FUCHSIA)
 // Sets the device scale factor for FontRenderParams to decide
 // if it should enable subpixel positioning.
