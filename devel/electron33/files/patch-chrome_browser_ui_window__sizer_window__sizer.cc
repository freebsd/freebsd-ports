--- chrome/browser/ui/window_sizer/window_sizer.cc.orig	2024-10-16 21:31:03 UTC
+++ chrome/browser/ui/window_sizer/window_sizer.cc
@@ -209,7 +209,7 @@ void WindowSizer::GetBrowserWindowBoundsAndShowState(
       browser, window_bounds, show_state);
 }
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Linux has its own implementation, see WindowSizerLinux.
 // static
 void WindowSizer::GetBrowserWindowBoundsAndShowState(
