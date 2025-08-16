--- electron/shell/browser/api/electron_api_base_window.h.orig	2025-08-14 14:48:00 UTC
+++ electron/shell/browser/api/electron_api_base_window.h
@@ -259,7 +259,7 @@ class BaseWindow : public gin_helper::TrackableObject<
   v8::Local<v8::Value> GetAccentColor() const;
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void SetTitleBarOverlay(const gin_helper::Dictionary& options,
                           gin_helper::Arguments* args);
 #endif
