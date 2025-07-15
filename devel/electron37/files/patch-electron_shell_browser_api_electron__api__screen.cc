--- electron/shell/browser/api/electron_api_screen.cc.orig	2025-07-02 10:12:01 UTC
+++ electron/shell/browser/api/electron_api_screen.cc
@@ -28,7 +28,7 @@
 #include "ui/display/win/screen_win.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "shell/browser/linux/x11_util.h"
 #endif
 
@@ -136,7 +136,7 @@ gfx::PointF Screen::ScreenToDIPPoint(const gfx::PointF
 gfx::PointF Screen::ScreenToDIPPoint(const gfx::PointF& point_px) {
 #if BUILDFLAG(IS_WIN)
   return display::win::GetScreenWin()->ScreenToDIPPoint(point_px);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (x11_util::IsX11()) {
     gfx::Point pt_px = gfx::ToFlooredPoint(point_px);
     display::Display display = GetDisplayNearestPoint(pt_px);
@@ -155,7 +155,7 @@ gfx::Point Screen::DIPToScreenPoint(const gfx::Point& 
 gfx::Point Screen::DIPToScreenPoint(const gfx::Point& point_dip) {
 #if BUILDFLAG(IS_WIN)
   return display::win::GetScreenWin()->DIPToScreenPoint(point_dip);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (x11_util::IsX11()) {
     display::Display display = GetDisplayNearestPoint(point_dip);
     gfx::Rect bounds_dip = display.bounds();
@@ -198,7 +198,7 @@ gin::ObjectTemplateBuilder Screen::GetObjectTemplateBu
       .SetMethod("getPrimaryDisplay", &Screen::GetPrimaryDisplay)
       .SetMethod("getAllDisplays", &Screen::GetAllDisplays)
       .SetMethod("getDisplayNearestPoint", &Screen::GetDisplayNearestPoint)
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       .SetMethod("screenToDipPoint", &Screen::ScreenToDIPPoint)
       .SetMethod("dipToScreenPoint", &Screen::DIPToScreenPoint)
 #endif
