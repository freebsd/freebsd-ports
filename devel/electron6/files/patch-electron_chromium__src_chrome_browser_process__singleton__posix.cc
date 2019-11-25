--- electron/chromium_src/chrome/browser/process_singleton_posix.cc.orig	2019-09-11 17:30:11 UTC
+++ electron/chromium_src/chrome/browser/process_singleton_posix.cc
@@ -95,7 +95,7 @@
 #include "net/base/network_interfaces.h"
 #include "ui/base/l10n/l10n_util.h"
 
-#if defined(TOOLKIT_VIEWS) && defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(TOOLKIT_VIEWS) && (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 #include "ui/views/linux_ui/linux_ui.h"
 #endif
 
@@ -862,7 +862,7 @@ ProcessSingleton::NotifyResult ProcessSingleton::Notif
     // The other process is shutting down, it's safe to start a new process.
     return PROCESS_NONE;
   } else if (strncmp(buf, kACKToken, base::size(kACKToken) - 1) == 0) {
-#if defined(TOOLKIT_VIEWS) && defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(TOOLKIT_VIEWS) && ((defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD))
     // Likely NULL in unit tests.
     views::LinuxUI* linux_ui = views::LinuxUI::instance();
     if (linux_ui)
