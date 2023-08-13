--- electron/shell/browser/electron_browser_main_parts.cc.orig	2023-08-09 14:05:20 UTC
+++ electron/shell/browser/electron_browser_main_parts.cc
@@ -76,7 +76,7 @@
 #include "ui/wm/core/wm_state.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/environment.h"
 #include "device/bluetooth/bluetooth_adapter_factory.h"
 #include "device/bluetooth/dbus/dbus_bluez_manager_wrapper_linux.h"
@@ -128,7 +128,7 @@ namespace electron {
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 class LinuxUiGetterImpl : public ui::LinuxUiGetter {
  public:
   LinuxUiGetterImpl() = default;
@@ -176,7 +176,7 @@ std::u16string MediaStringProvider(media::MessageId id
   }
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // GTK does not provide a way to check if current theme is dark, so we compare
 // the text and background luminosity to get a result.
 // This trick comes from FireFox.
@@ -194,7 +194,7 @@ void UpdateDarkThemeSetting() {
 
 }  // namespace
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 class DarkThemeObserver : public ui::NativeThemeObserver {
  public:
   DarkThemeObserver() = default;
@@ -246,7 +246,7 @@ int ElectronBrowserMainParts::PreEarlyInitialization()
 #if BUILDFLAG(IS_POSIX)
   HandleSIGCHLD();
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   DetectOzonePlatform();
   ui::OzonePlatform::PreEarlyInitialization();
 #endif
@@ -334,7 +334,7 @@ int ElectronBrowserMainParts::PreCreateThreads() {
   // happen before the ResourceBundle is loaded
   if (locale.empty())
     l10n_util::OverrideLocaleWithCocoaLocale();
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // l10n_util::GetApplicationLocaleInternal uses g_get_language_names(),
   // which keys off of getenv("LC_ALL").
   // We must set this env first to make ui::ResourceBundle accept the custom
@@ -365,7 +365,7 @@ int ElectronBrowserMainParts::PreCreateThreads() {
   ElectronBrowserClient::SetApplicationLocale(app_locale);
   fake_browser_process_->SetApplicationLocale(app_locale);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Reset to the original LC_ALL since we should not be changing it.
   if (!locale.empty()) {
     if (lc_all)
@@ -425,7 +425,7 @@ void ElectronBrowserMainParts::PostDestroyThreads() {
 }
 
 void ElectronBrowserMainParts::ToolkitInitialized() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto* linux_ui = ui::GetDefaultLinuxUi();
   CHECK(linux_ui);
   linux_ui_getter_ = std::make_unique<LinuxUiGetterImpl>();
@@ -539,7 +539,7 @@ void ElectronBrowserMainParts::WillRunMainMessageLoop(
 }
 
 void ElectronBrowserMainParts::PostCreateMainMessageLoop() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   std::string app_name = electron::Browser::Get()->GetName();
 #endif
 #if BUILDFLAG(IS_LINUX)
@@ -549,7 +549,9 @@ void ElectronBrowserMainParts::PostCreateMainMessageLo
       std::move(shutdown_cb),
       content::GetUIThreadTaskRunner({content::BrowserTaskType::kUserInput}));
   bluez::DBusBluezManagerWrapperLinux::Initialize();
+#endif
 
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Set up crypt config. This needs to be done before anything starts the
   // network service, as the raw encryption key needs to be shared with the
   // network service for encrypted cookie storage.
@@ -650,7 +652,7 @@ void ElectronBrowserMainParts::PostMainMessageLoopRun(
   fake_browser_process_->PostMainMessageLoopRun();
   content::DevToolsAgentHost::StopRemoteDebuggingPipeHandler();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   ui::OzonePlatform::GetInstance()->PostMainMessageLoopRun();
 #endif
 }
