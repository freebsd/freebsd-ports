--- ui/display/screen.h.orig	2025-04-22 20:15:27 UTC
+++ ui/display/screen.h
@@ -140,7 +140,7 @@ class DISPLAY_EXPORT Screen {
   // (both of which may or may not be `nearest_id`).
   display::ScreenInfos GetScreenInfosNearestDisplay(int64_t nearest_id) const;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Object which suspends the platform-specific screensaver for the duration of
   // its existence.
   class ScreenSaverSuspender {
@@ -246,7 +246,7 @@ class DISPLAY_EXPORT Screen {
   int64_t display_id_for_new_windows_;
   int64_t scoped_display_id_for_new_windows_ = display::kInvalidDisplayId;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   uint32_t screen_saver_suspension_count_ = 0;
 #endif  // BUILDFLAG(IS_LINUX)
 };
