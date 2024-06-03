--- electron/shell/browser/api/electron_api_desktop_capturer.cc.orig	2024-04-16 14:29:17 UTC
+++ electron/shell/browser/api/electron_api_desktop_capturer.cc
@@ -41,7 +41,7 @@
 #include "ui/gfx/x/randr.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Private function in ui/base/x/x11_display_util.cc
 base::flat_map<x11::RandR::Output, int> GetMonitors(
     std::pair<uint32_t, uint32_t> version,
