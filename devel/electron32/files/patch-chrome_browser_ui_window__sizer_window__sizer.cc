--- chrome/browser/ui/window_sizer/window_sizer.cc.orig	2024-06-18 21:43:25 UTC
+++ chrome/browser/ui/window_sizer/window_sizer.cc
@@ -210,7 +210,7 @@ void WindowSizer::GetBrowserWindowBoundsAndShowState(
       browser, window_bounds, show_state);
 }
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Linux has its own implementation, see WindowSizerLinux.
 // static
 void WindowSizer::GetBrowserWindowBoundsAndShowState(
