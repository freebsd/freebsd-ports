--- electron/atom/browser/api/atom_api_web_contents.cc.orig	2019-12-17 03:11:25 UTC
+++ electron/atom/browser/api/atom_api_web_contents.cc
@@ -97,11 +97,11 @@
 #include "ui/base/cocoa/defaults_utils.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "ui/views/linux_ui/linux_ui.h"
 #endif
 
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
 #include "content/public/common/renderer_preferences.h"
 #include "ui/gfx/font_render_params.h"
 #endif
@@ -428,7 +428,7 @@ void WebContents::InitWithSessionAndOptions(
   auto* prefs = web_contents()->GetMutableRendererPrefs();
   prefs->accept_languages = g_browser_process->GetApplicationLocale();
 
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
   // Update font settings.
   static const base::NoDestructor<gfx::FontRenderParams> params(
       gfx::GetFontRenderParams(gfx::FontRenderParamsQuery(), nullptr));
@@ -445,7 +445,7 @@ void WebContents::InitWithSessionAndOptions(
   base::TimeDelta interval;
   if (ui::TextInsertionCaretBlinkPeriod(&interval))
     prefs->caret_blink_interval = interval;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   views::LinuxUI* linux_ui = views::LinuxUI::instance();
   if (linux_ui)
     prefs->caret_blink_interval = linux_ui->GetCursorBlinkInterval();
