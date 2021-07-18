--- content/browser/renderer_host/render_view_host_impl.cc.orig	2021-04-22 07:51:51 UTC
+++ content/browser/renderer_host/render_view_host_impl.cc
@@ -258,7 +258,7 @@ void RenderViewHostImpl::GetPlatformSpecificPrefs(
       display::win::ScreenWin::GetSystemMetricsInDIP(SM_CYVSCROLL);
   prefs->arrow_bitmap_width_horizontal_scroll_bar_in_dips =
       display::win::ScreenWin::GetSystemMetricsInDIP(SM_CXHSCROLL);
-#elif defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   prefs->system_font_family_name = gfx::Font().GetFontName();
 #elif defined(OS_FUCHSIA)
   // Make Blink's "focus ring" invisible. The focus ring is a hairline border
