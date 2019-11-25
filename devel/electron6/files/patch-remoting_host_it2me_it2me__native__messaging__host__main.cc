--- remoting/host/it2me/it2me_native_messaging_host_main.cc.orig	2019-09-10 11:14:11 UTC
+++ remoting/host/it2me/it2me_native_messaging_host_main.cc
@@ -27,12 +27,12 @@
 #include "remoting/host/resources.h"
 #include "remoting/host/usage_stats_consent.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include <gtk/gtk.h>
 
 #include "base/linux_util.h"
 #include "ui/gfx/x/x11.h"
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 #if defined(OS_MACOSX)
 #include "base/mac/scoped_nsautorelease_pool.h"
@@ -106,7 +106,7 @@ int It2MeNativeMessagingHostMain(int argc, char** argv
 
   remoting::LoadResources("");
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Required in order for us to run multiple X11 threads.
   XInitThreads();
 
@@ -122,7 +122,7 @@ int It2MeNativeMessagingHostMain(int argc, char** argv
   // Need to prime the host OS version value for linux to prevent IO on the
   // network thread. base::GetLinuxDistro() caches the result.
   base::GetLinuxDistro();
-#endif  // OS_LINUX
+#endif  // OS_LINUX || OS_BSD
 
   base::File read_file;
   base::File write_file;
