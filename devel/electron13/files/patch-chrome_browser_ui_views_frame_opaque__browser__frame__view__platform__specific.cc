--- chrome/browser/ui/views/frame/opaque_browser_frame_view_platform_specific.cc.orig	2021-01-07 00:36:25 UTC
+++ chrome/browser/ui/views/frame/opaque_browser_frame_view_platform_specific.cc
@@ -6,7 +6,7 @@
 
 #include "build/build_config.h"
 
-#if !defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if !defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_BSD)
 
 // static
 std::unique_ptr<OpaqueBrowserFrameViewPlatformSpecific>
