--- chrome/browser/ui/window_sizer/window_sizer.cc.orig	2023-10-19 19:58:08 UTC
+++ chrome/browser/ui/window_sizer/window_sizer.cc
@@ -216,7 +216,7 @@ void WindowSizer::GetBrowserWindowBoundsAndShowState(
       browser, window_bounds, show_state);
 }
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Linux has its own implementation, see WindowSizerLinux.
 // static
 void WindowSizer::GetBrowserWindowBoundsAndShowState(
