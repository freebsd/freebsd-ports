--- electron/shell/browser/electron_browser_main_parts.cc.orig	2022-05-11 15:32:29 UTC
+++ electron/shell/browser/electron_browser_main_parts.cc
@@ -61,7 +61,7 @@
 #include "ui/wm/core/wm_state.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/environment.h"
 #include "base/threading/thread_task_runner_handle.h"
 #include "device/bluetooth/bluetooth_adapter_factory.h"
@@ -140,7 +140,7 @@ std::u16string MediaStringProvider(media::MessageId id
   }
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // GTK does not provide a way to check if current theme is dark, so we compare
 // the text and background luminosity to get a result.
 // This trick comes from FireFox.
@@ -158,7 +158,7 @@ void UpdateDarkThemeSetting() {
 
 }  // namespace
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 class DarkThemeObserver : public ui::NativeThemeObserver {
  public:
   DarkThemeObserver() = default;
@@ -211,7 +211,7 @@ int ElectronBrowserMainParts::PreEarlyInitialization()
 #if defined(OS_POSIX)
   HandleSIGCHLD();
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   ui::OzonePlatform::PreEarlyInitialization();
 #endif
 
@@ -272,7 +272,7 @@ int ElectronBrowserMainParts::PreCreateThreads() {
 #if defined(USE_AURA)
   screen_ = views::CreateDesktopScreen();
   display::Screen::SetScreenInstance(screen_.get());
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   views::LinuxUI::instance()->UpdateDeviceScaleFactor();
 #endif
 #endif
@@ -289,7 +289,7 @@ int ElectronBrowserMainParts::PreCreateThreads() {
   // happen before the ResourceBundle is loaded
   if (locale.empty())
     l10n_util::OverrideLocaleWithCocoaLocale();
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   // l10n_util::GetApplicationLocaleInternal uses g_get_language_names(),
   // which keys off of getenv("LC_ALL").
   // We must set this env first to make ui::ResourceBundle accept the custom
@@ -312,7 +312,7 @@ int ElectronBrowserMainParts::PreCreateThreads() {
   ElectronBrowserClient::SetApplicationLocale(app_locale);
   fake_browser_process_->SetApplicationLocale(app_locale);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Reset to the original LC_ALL since we should not be changing it.
   if (!locale.empty()) {
     if (lc_all)
@@ -359,7 +359,7 @@ void ElectronBrowserMainParts::PostDestroyThreads() {
 }
 
 void ElectronBrowserMainParts::ToolkitInitialized() {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   auto linux_ui = BuildGtkUi();
   linux_ui->Initialize();
   DCHECK(ui::LinuxInputMethodContextFactory::instance());
@@ -505,7 +505,7 @@ void ElectronBrowserMainParts::PostMainMessageLoopRun(
   fake_browser_process_->PostMainMessageLoopRun();
   content::DevToolsAgentHost::StopRemoteDebuggingPipeHandler();
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   ui::OzonePlatform::GetInstance()->PostMainMessageLoopRun();
 #endif
 }
