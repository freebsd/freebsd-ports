--- electron/shell/browser/api/electron_api_desktop_capturer.cc.orig	2023-10-20 08:29:17 UTC
+++ electron/shell/browser/api/electron_api_desktop_capturer.cc
@@ -37,7 +37,7 @@
 #include "third_party/webrtc/modules/desktop_capture/win/dxgi_duplicator_controller.h"
 #include "third_party/webrtc/modules/desktop_capture/win/screen_capturer_win_directx.h"
 #include "ui/display/win/display_info.h"
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #if defined(USE_OZONE_PLATFORM_X11)
 #include "base/logging.h"
 #include "ui/base/x/x11_display_util.h"
@@ -49,7 +49,7 @@
 #endif  // defined(USE_OZONE_PLATFORM_X11)
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Private function in ui/base/x/x11_display_util.cc
 std::map<x11::RandR::Output, int> GetMonitors(int version,
                                               x11::RandR* randr,
@@ -389,7 +389,7 @@ void DesktopCapturer::UpdateSourcesList(DesktopMediaLi
     for (auto& source : screen_sources) {
       source.display_id = base::NumberToString(source.media_list_source.id.id);
     }
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #if defined(USE_OZONE_PLATFORM_X11)
     // On Linux, with X11, the source id is the numeric value of the
     // display name atom and the display id is either the EDID or the
