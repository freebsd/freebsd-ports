--- remoting/host/it2me/it2me_native_messaging_host_main.cc.orig	2019-03-15 06:37:31 UTC
+++ remoting/host/it2me/it2me_native_messaging_host_main.cc
@@ -25,7 +25,7 @@
 #include "remoting/host/resources.h"
 #include "remoting/host/usage_stats_consent.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include <gtk/gtk.h>
 
 #include "base/linux_util.h"
@@ -102,7 +102,7 @@ int It2MeNativeMessagingHostMain(int argc, char** argv
 
   remoting::LoadResources("");
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Required in order for us to run multiple X11 threads.
   XInitThreads();
 
