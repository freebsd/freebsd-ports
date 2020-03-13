--- electron/shell/browser/api/atom_api_web_contents.cc.orig	2020-02-20 17:38:02 UTC
+++ electron/shell/browser/api/atom_api_web_contents.cc
@@ -104,11 +104,11 @@
 #include "ui/base/cocoa/defaults_utils.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "ui/views/linux_ui/linux_ui.h"
 #endif
 
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
 #include "third_party/blink/public/mojom/renderer_preferences.mojom.h"
 #include "ui/gfx/font_render_params.h"
 #endif
@@ -482,7 +482,7 @@ void WebContents::InitWithSessionAndOptions(
   auto* prefs = web_contents()->GetMutableRendererPrefs();
   prefs->accept_languages = g_browser_process->GetApplicationLocale();
 
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
   // Update font settings.
   static const base::NoDestructor<gfx::FontRenderParams> params(
       gfx::GetFontRenderParams(gfx::FontRenderParamsQuery(), nullptr));
@@ -499,7 +499,7 @@ void WebContents::InitWithSessionAndOptions(
   base::TimeDelta interval;
   if (ui::TextInsertionCaretBlinkPeriod(&interval))
     prefs->caret_blink_interval = interval;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   views::LinuxUI* linux_ui = views::LinuxUI::instance();
   if (linux_ui)
     prefs->caret_blink_interval = linux_ui->GetCursorBlinkInterval();
