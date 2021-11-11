--- electron/shell/browser/api/electron_api_web_contents.cc.orig	2021-10-11 17:12:26 UTC
+++ electron/shell/browser/api/electron_api_web_contents.cc
@@ -148,11 +148,11 @@
 #include "ui/base/cocoa/defaults_utils.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "ui/views/linux_ui/linux_ui.h"
 #endif
 
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
 #include "ui/gfx/font_render_params.h"
 #endif
 
@@ -391,7 +391,7 @@ base::Optional<base::TimeDelta> GetCursorBlinkInterval
   base::TimeDelta interval;
   if (ui::TextInsertionCaretBlinkPeriod(&interval))
     return interval;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   if (auto* linux_ui = views::LinuxUI::instance())
     return linux_ui->GetCursorBlinkInterval();
 #elif defined(OS_WIN)
@@ -804,7 +804,7 @@ void WebContents::InitWithSessionAndOptions(
   accept_languages.pop_back();
   prefs->accept_languages = accept_languages;
 
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
   // Update font settings.
   static const base::NoDestructor<gfx::FontRenderParams> params(
       gfx::GetFontRenderParams(gfx::FontRenderParamsQuery(), nullptr));
@@ -2136,7 +2136,7 @@ void WebContents::ForcefullyCrashRenderer() {
 
   content::RenderProcessHost* rph = rwh->GetProcess();
   if (rph) {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
     // A generic |CrashDumpHungChildProcess()| is not implemented for Linux.
     // Instead we send an explicit IPC to crash on the renderer's IO thread.
     rph->ForceCrash();
@@ -2702,7 +2702,7 @@ void WebContents::CopyImageAt(int x, int y) {
 void WebContents::Focus() {
   // Focusing on WebContents does not automatically focus the window on macOS
   // and Linux, do it manually to match the behavior on Windows.
-#if defined(OS_MAC) || defined(OS_LINUX)
+#if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
   if (owner_window())
     owner_window()->Focus(true);
 #endif
@@ -3565,7 +3565,7 @@ gfx::ImageSkia WebContents::GetDevToolsWindowIcon() {
 }
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 void WebContents::GetDevToolsWindowWMClass(std::string* name,
                                            std::string* class_name) {
   *class_name = Browser::Get()->GetName();
