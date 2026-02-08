--- remoting/host/it2me/it2me_native_messaging_host_main.cc.orig	2025-06-30 07:04:30 UTC
+++ remoting/host/it2me/it2me_native_messaging_host_main.cc
@@ -29,7 +29,7 @@
 #include "remoting/host/resources.h"
 #include "remoting/host/usage_stats_consent.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #if defined(REMOTING_USE_X11)
 #include <gtk/gtk.h>
 #include "base/linux_util.h"
@@ -43,7 +43,7 @@
 #include "remoting/host/mac/permission_utils.h"
 #endif  // BUILDFLAG(IS_APPLE)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "remoting/base/crash/crash_reporting_crashpad.h"
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -79,7 +79,7 @@ int It2MeNativeMessagingHostMain(int argc, char** argv
 // Creates a It2MeNativeMessagingHost instance, attaches it to stdin/stdout and
 // runs the task executor until It2MeNativeMessagingHost signals shutdown.
 int It2MeNativeMessagingHostMain(int argc, char** argv) {
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && defined(REMOTING_USE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && defined(REMOTING_USE_X11)
   // Initialize Xlib for multi-threaded use, allowing non-Chromium code to
   // use X11 safely (such as the WebRTC capturer, GTK ...)
   x11::InitXlib();
@@ -104,7 +104,7 @@ int It2MeNativeMessagingHostMain(int argc, char** argv
   // needs to be initialized first, so that the preference for crash-reporting
   // can be looked up in the config file.
   if (IsUsageStatsAllowed()) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     InitializeCrashpadReporting();
 #elif BUILDFLAG(IS_WIN)
     InitializeBreakpadReporting();
@@ -129,7 +129,7 @@ int It2MeNativeMessagingHostMain(int argc, char** argv
 
   remoting::LoadResources("");
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && defined(REMOTING_USE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && defined(REMOTING_USE_X11)
   // Required for any calls into GTK functions, such as the Disconnect and
   // Continue windows. Calling with nullptr arguments because we don't have
   // any command line arguments for gtk to consume.
@@ -257,7 +257,7 @@ int It2MeNativeMessagingHostMain(int argc, char** argv
       PolicyWatcher::CreateWithTaskRunner(context->file_task_runner(),
                                           context->management_service());
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && defined(REMOTING_USE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && defined(REMOTING_USE_X11)
   scoped_refptr<AutoThreadTaskRunner> input_task_runner;
   // Create an X11EventSource on all UI threads, so the global X11 connection
   // (x11::Connection::Get()) can dispatch X events.
@@ -281,7 +281,7 @@ int It2MeNativeMessagingHostMain(int argc, char** argv
   // Run the loop until channel is alive.
   run_loop.Run();
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && defined(REMOTING_USE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && defined(REMOTING_USE_X11)
   input_task_runner->PostTask(FROM_HERE, base::BindOnce([]() {
                                 delete ui::X11EventSource::GetInstance();
                               }));
