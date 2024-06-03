--- headless/lib/browser/headless_browser_main_parts_posix.cc.orig	2023-10-19 19:58:24 UTC
+++ headless/lib/browser/headless_browser_main_parts_posix.cc
@@ -21,13 +21,13 @@
 #include "content/public/browser/browser_thread.h"
 #include "headless/lib/browser/headless_browser_impl.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/command_line.h"
 #include "components/os_crypt/sync/key_storage_config_linux.h"
 #include "components/os_crypt/sync/os_crypt.h"
 #include "headless/public/switches.h"
 
-#if defined(USE_DBUS)
+#if defined(USE_DBUS) && !BUILDFLAG(IS_BSD)
 #include "device/bluetooth/dbus/bluez_dbus_manager.h"
 #endif
 
@@ -161,7 +161,7 @@ class BrowserShutdownHandler {
 
 }  // namespace
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr char kProductName[] = "HeadlessChrome";
 #endif
 
@@ -169,9 +169,9 @@ void HeadlessBrowserMainParts::PostCreateMainMessageLo
   BrowserShutdownHandler::Install(base::BindOnce(
       &HeadlessBrowserImpl::ShutdownWithExitCode, browser_->GetWeakPtr()));
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
-#if defined(USE_DBUS)
+#if defined(USE_DBUS) && !BUILDFLAG(IS_BSD)
   bluez::BluezDBusManager::Initialize(/*system_bus=*/nullptr);
 #endif
 
