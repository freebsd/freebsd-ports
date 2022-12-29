--- chrome/browser/ui/window_sizer/window_sizer.cc.orig	2022-09-24 10:57:32 UTC
+++ chrome/browser/ui/window_sizer/window_sizer.cc
@@ -173,7 +173,7 @@ void WindowSizer::GetBrowserWindowBoundsAndShowState(
       browser, window_bounds, show_state);
 }
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Linux has its own implementation, see WindowSizerLinux.
 // static
 void WindowSizer::GetBrowserWindowBoundsAndShowState(
