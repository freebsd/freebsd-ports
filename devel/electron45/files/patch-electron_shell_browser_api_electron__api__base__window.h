--- electron/shell/browser/api/electron_api_base_window.h.orig	2026-10-26 21:12:45 UTC
+++ electron/shell/browser/api/electron_api_base_window.h
@@ -301,7 +301,7 @@ class BaseWindow : public gin_helper::TrackableObject<
   v8::Local<v8::Value> GetAccentColor() const;
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void SetTitleBarOverlay(const gin_helper::Dictionary& options,
                           gin::Arguments* args);
 #endif
