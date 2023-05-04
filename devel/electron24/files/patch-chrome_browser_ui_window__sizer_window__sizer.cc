--- chrome/browser/ui/window_sizer/window_sizer.cc.orig	2023-03-30 00:33:45 UTC
+++ chrome/browser/ui/window_sizer/window_sizer.cc
@@ -203,7 +203,7 @@ void WindowSizer::GetBrowserWindowBoundsAndShowState(
       browser, window_bounds, show_state);
 }
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Linux has its own implementation, see WindowSizerLinux.
 // static
 void WindowSizer::GetBrowserWindowBoundsAndShowState(
