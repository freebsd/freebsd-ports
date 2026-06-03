--- chrome/browser/ui/window_sizer/window_sizer.cc.orig	2026-03-13 16:54:03 UTC
+++ chrome/browser/ui/window_sizer/window_sizer.cc
@@ -226,7 +226,7 @@ void WindowSizer::GetBrowserWindowBoundsAndShowState(
       browser, window_bounds, show_state);
 }
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Linux has its own implementation, see WindowSizerLinux.
 // static
 void WindowSizer::GetBrowserWindowBoundsAndShowState(
