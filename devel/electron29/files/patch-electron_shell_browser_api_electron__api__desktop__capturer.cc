--- electron/shell/browser/api/electron_api_desktop_capturer.cc.orig	2024-08-09 17:08:27 UTC
+++ electron/shell/browser/api/electron_api_desktop_capturer.cc
@@ -45,7 +45,7 @@
 #include "ui/base/cocoa/permissions_utils.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Private function in ui/base/x/x11_display_util.cc
 std::map<x11::RandR::Output, int> GetMonitors(
     std::pair<uint32_t, uint32_t> version,
