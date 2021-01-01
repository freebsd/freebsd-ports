--- chrome/browser/ui/views/frame/opaque_browser_frame_view_layout.cc.orig	2019-03-15 06:37:07 UTC
+++ chrome/browser/ui/views/frame/opaque_browser_frame_view_layout.cc
@@ -20,7 +20,7 @@ namespace {
 
 constexpr int kCaptionButtonHeight = 18;
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 // Default spacing around window caption buttons.
 constexpr int kCaptionButtonSpacing = 2;
 #else
