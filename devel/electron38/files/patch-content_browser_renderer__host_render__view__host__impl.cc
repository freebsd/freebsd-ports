--- content/browser/renderer_host/render_view_host_impl.cc.orig	2025-09-10 14:33:47 UTC
+++ content/browser/renderer_host/render_view_host_impl.cc
@@ -275,7 +275,7 @@ void RenderViewHostImpl::GetPlatformSpecificPrefs(
       display::win::GetScreenWin()->GetSystemMetricsInDIP(SM_CYVSCROLL);
   prefs->arrow_bitmap_width_horizontal_scroll_bar_in_dips =
       display::win::GetScreenWin()->GetSystemMetricsInDIP(SM_CXHSCROLL);
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   base::CommandLine* command_line = base::CommandLine::ForCurrentProcess();
   if (command_line->HasSwitch(switches::kSystemFontFamily)) {
     prefs->system_font_family_name =
