--- electron/shell/browser/api/electron_api_web_contents.cc.orig	2025-10-27 17:58:27 UTC
+++ electron/shell/browser/api/electron_api_web_contents.cc
@@ -161,11 +161,11 @@
 #include "ui/base/cocoa/defaults_utils.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "ui/aura/window.h"
 #include "ui/gfx/font_render_params.h"
 #endif
@@ -197,7 +197,7 @@
 #include "content/public/browser/plugin_service.h"
 #endif
 
-#if !IS_MAS_BUILD()
+#if !IS_MAS_BUILD() && !BUILDFLAG(IS_BSD)
 #include "chrome/browser/hang_monitor/hang_crash_dump.h"  // nogncheck
 #endif
 
@@ -571,7 +571,7 @@ std::optional<base::TimeDelta> GetCursorBlinkInterval(
       ui::TextInsertionCaretBlinkPeriodFromDefaults());
   if (system_value)
     return *system_value;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (auto* native_theme = ui::NativeTheme::GetInstanceForNativeUi())
     return native_theme->caret_blink_interval();
 #elif BUILDFLAG(IS_WIN)
@@ -936,7 +936,7 @@ void WebContents::InitWithSessionAndOptions(
   accept_languages.pop_back();
   prefs->accept_languages = accept_languages;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // Update font settings.
   static const gfx::FontRenderParams params(
       gfx::GetFontRenderParams(gfx::FontRenderParamsQuery(), nullptr));
@@ -2710,13 +2710,13 @@ void WebContents::ForcefullyCrashRenderer() {
 
   content::RenderProcessHost* rph = rwh->GetProcess();
   if (rph) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     // A generic |CrashDumpHungChildProcess()| is not implemented for Linux.
     // Instead we send an explicit IPC to crash on the renderer's IO thread.
     rph->ForceCrash();
 #else
     // Try to generate a crash report for the hung process.
-#if !IS_MAS_BUILD()
+#if !IS_MAS_BUILD() && !BUILDFLAG(IS_BSD)
     CrashDumpHungChildProcess(rph->GetProcess().Handle());
 #endif
     rph->Shutdown(content::RESULT_CODE_HUNG);
@@ -3400,7 +3400,7 @@ void WebContents::Focus() {
 void WebContents::Focus() {
   // Focusing on WebContents does not automatically focus the window on macOS
   // and Linux, do it manually to match the behavior on Windows.
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (owner_window())
     owner_window()->Focus(true);
 #endif
@@ -4284,7 +4284,7 @@ ui::ImageModel WebContents::GetDevToolsWindowIcon() {
 }
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void WebContents::GetDevToolsWindowWMClass(std::string* name,
                                            std::string* class_name) {
   *class_name = Browser::Get()->GetName();
