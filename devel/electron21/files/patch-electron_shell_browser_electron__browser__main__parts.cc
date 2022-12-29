--- electron/shell/browser/electron_browser_main_parts.cc.orig	2022-10-19 17:31:10.000000000 +0200
+++ electron/shell/browser/electron_browser_main_parts.cc	2022-12-02 17:37:56.982763000 +0100
@@ -67,7 +67,7 @@
 #include "ui/wm/core/wm_state.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/environment.h"
 #include "base/threading/thread_task_runner_handle.h"
 #include "device/bluetooth/bluetooth_adapter_factory.h"
@@ -149,7 +149,7 @@ std::u16string MediaStringProvider(media::MessageId id
   }
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // GTK does not provide a way to check if current theme is dark, so we compare
 // the text and background luminosity to get a result.
 // This trick comes from FireFox.
@@ -167,7 +167,7 @@ void UpdateDarkThemeSetting() {
 
 }  // namespace
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 class DarkThemeObserver : public ui::NativeThemeObserver {
  public:
   DarkThemeObserver() = default;
@@ -219,7 +219,7 @@ int ElectronBrowserMainParts::PreEarlyInitialization()
 #if BUILDFLAG(IS_POSIX)
   HandleSIGCHLD();
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   DetectOzonePlatform();
   ui::OzonePlatform::PreEarlyInitialization();
 #endif
@@ -304,7 +304,7 @@ int ElectronBrowserMainParts::PreCreateThreads() {
   // happen before the ResourceBundle is loaded
   if (locale.empty())
     l10n_util::OverrideLocaleWithCocoaLocale();
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // l10n_util::GetApplicationLocaleInternal uses g_get_language_names(),
   // which keys off of getenv("LC_ALL").
   // We must set this env first to make ui::ResourceBundle accept the custom
@@ -335,7 +335,7 @@ int ElectronBrowserMainParts::PreCreateThreads() {
   ElectronBrowserClient::SetApplicationLocale(app_locale);
   fake_browser_process_->SetApplicationLocale(app_locale);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Reset to the original LC_ALL since we should not be changing it.
   if (!locale.empty()) {
     if (lc_all)
@@ -382,7 +382,7 @@ void ElectronBrowserMainParts::ToolkitInitialized() {
 }
 
 void ElectronBrowserMainParts::ToolkitInitialized() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto linux_ui = ui::CreateLinuxUi();
 
   // Try loading gtk symbols used by Electron.
@@ -502,7 +502,9 @@ void ElectronBrowserMainParts::PostCreateMainMessageLo
   ui::OzonePlatform::GetInstance()->PostCreateMainMessageLoop(
       std::move(shutdown_cb));
   bluez::DBusBluezManagerWrapperLinux::Initialize();
+#endif
 
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Set up crypt config. This needs to be done before anything starts the
   // network service, as the raw encryption key needs to be shared with the
   // network service for encrypted cookie storage.
@@ -561,7 +563,7 @@ void ElectronBrowserMainParts::PostMainMessageLoopRun(
   fake_browser_process_->PostMainMessageLoopRun();
   content::DevToolsAgentHost::StopRemoteDebuggingPipeHandler();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   ui::OzonePlatform::GetInstance()->PostMainMessageLoopRun();
 #endif
 }
