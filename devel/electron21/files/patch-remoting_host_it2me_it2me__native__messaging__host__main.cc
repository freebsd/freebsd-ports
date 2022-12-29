--- remoting/host/it2me/it2me_native_messaging_host_main.cc.orig	2022-06-17 14:20:10 UTC
+++ remoting/host/it2me/it2me_native_messaging_host_main.cc
@@ -30,7 +30,7 @@
 #include "remoting/host/resources.h"
 #include "remoting/host/usage_stats_consent.h"
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && defined(REMOTING_USE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && defined(REMOTING_USE_X11)
 #include <gtk/gtk.h>
 
 #include "base/linux_util.h"
@@ -77,7 +77,7 @@ bool CurrentProcessHasUiAccess() {
 // Creates a It2MeNativeMessagingHost instance, attaches it to stdin/stdout and
 // runs the task executor until It2MeNativeMessagingHost signals shutdown.
 int It2MeNativeMessagingHostMain(int argc, char** argv) {
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && defined(REMOTING_USE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && defined(REMOTING_USE_X11)
   // Initialize Xlib for multi-threaded use, allowing non-Chromium code to
   // use X11 safely (such as the WebRTC capturer, GTK ...)
   x11::InitXlib();
@@ -123,7 +123,7 @@ int It2MeNativeMessagingHostMain(int argc, char** argv
 
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
   // Create an X11EventSource on all UI threads, so the global X11 connection
   // (x11::Connection::Get()) can dispatch X events.
   auto event_source =
@@ -280,7 +280,7 @@ int It2MeNativeMessagingHostMain(int argc, char** argv
   // Run the loop until channel is alive.
   run_loop.Run();
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && defined(REMOTING_USE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && defined(REMOTING_USE_X11)
   input_task_runner->PostTask(FROM_HERE, base::BindOnce([]() {
                                 delete ui::X11EventSource::GetInstance();
                               }));
