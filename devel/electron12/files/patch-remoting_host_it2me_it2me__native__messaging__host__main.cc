--- remoting/host/it2me/it2me_native_messaging_host_main.cc.orig	2021-04-14 01:08:53 UTC
+++ remoting/host/it2me/it2me_native_messaging_host_main.cc
@@ -30,12 +30,12 @@
 #include "remoting/host/switches.h"
 #include "remoting/host/usage_stats_consent.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include <gtk/gtk.h>
 
 #include "base/linux_util.h"
 #include "ui/events/platform/x11/x11_event_source.h"
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 #if defined(OS_APPLE)
 #include "base/mac/mac_util.h"
@@ -114,7 +114,7 @@ int It2MeNativeMessagingHostMain(int argc, char** argv
 
   remoting::LoadResources("");
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // Create an X11EventSource so the global X11 connection
   // (x11::Connection::Get()) can dispatch X events.
   auto event_source =
@@ -132,7 +132,7 @@ int It2MeNativeMessagingHostMain(int argc, char** argv
   // Need to prime the host OS version value for linux to prevent IO on the
   // network thread. base::GetLinuxDistro() caches the result.
   base::GetLinuxDistro();
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
   base::File read_file;
   base::File write_file;
