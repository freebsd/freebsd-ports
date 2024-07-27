--- electron/shell/browser/api/electron_api_web_contents.cc.orig	2024-07-24 17:23:33 UTC
+++ electron/shell/browser/api/electron_api_web_contents.cc
@@ -153,11 +153,11 @@
 #include "ui/base/cocoa/defaults_utils.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "ui/gfx/font_render_params.h"
 #endif
 
@@ -517,7 +517,7 @@ std::optional<base::TimeDelta> GetCursorBlinkInterval(
       ui::TextInsertionCaretBlinkPeriodFromDefaults());
   if (system_value)
     return *system_value;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (auto* linux_ui = ui::LinuxUi::instance())
     return linux_ui->GetCursorBlinkInterval();
 #elif BUILDFLAG(IS_WIN)
@@ -881,7 +881,7 @@ void WebContents::InitWithSessionAndOptions(
   accept_languages.pop_back();
   prefs->accept_languages = accept_languages;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // Update font settings.
   static const gfx::FontRenderParams params(
       gfx::GetFontRenderParams(gfx::FontRenderParamsQuery(), nullptr));
@@ -2618,7 +2618,7 @@ void WebContents::ForcefullyCrashRenderer() {
 
   content::RenderProcessHost* rph = rwh->GetProcess();
   if (rph) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     // A generic |CrashDumpHungChildProcess()| is not implemented for Linux.
     // Instead we send an explicit IPC to crash on the renderer's IO thread.
     rph->ForceCrash();
@@ -3300,7 +3300,7 @@ void WebContents::Focus() {
 void WebContents::Focus() {
   // Focusing on WebContents does not automatically focus the window on macOS
   // and Linux, do it manually to match the behavior on Windows.
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (owner_window())
     owner_window()->Focus(true);
 #endif
@@ -4150,7 +4150,7 @@ ui::ImageModel WebContents::GetDevToolsWindowIcon() {
 }
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void WebContents::GetDevToolsWindowWMClass(std::string* name,
                                            std::string* class_name) {
   *class_name = Browser::Get()->GetName();
