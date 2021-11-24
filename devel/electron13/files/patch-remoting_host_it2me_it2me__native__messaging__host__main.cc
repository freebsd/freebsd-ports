--- remoting/host/it2me/it2me_native_messaging_host_main.cc.orig	2021-07-15 19:13:43 UTC
+++ remoting/host/it2me/it2me_native_messaging_host_main.cc
@@ -30,13 +30,13 @@
 #include "remoting/host/switches.h"
 #include "remoting/host/usage_stats_consent.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include <gtk/gtk.h>
 
 #include "base/linux_util.h"
 #include "ui/events/platform/x11/x11_event_source.h"
 #include "ui/gfx/x/xlib_support.h"
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 #if defined(OS_APPLE)
 #include "base/mac/mac_util.h"
@@ -76,11 +76,11 @@ bool CurrentProcessHasUiAccess() {
 // Creates a It2MeNativeMessagingHost instance, attaches it to stdin/stdout and
 // runs the task executor until It2MeNativeMessagingHost signals shutdown.
 int It2MeNativeMessagingHostMain(int argc, char** argv) {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // Initialize Xlib for multi-threaded use, allowing non-Chromium code to
   // use X11 safely (such as the WebRTC capturer, GTK ...)
   x11::InitXlib();
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
   // This object instance is required by Chrome code (such as
   // SingleThreadTaskExecutor).
@@ -121,7 +121,7 @@ int It2MeNativeMessagingHostMain(int argc, char** argv
 
   remoting::LoadResources("");
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // Required for any calls into GTK functions, such as the Disconnect and
   // Continue windows. Calling with nullptr arguments because we don't have
   // any command line arguments for gtk to consume.
@@ -134,7 +134,7 @@ int It2MeNativeMessagingHostMain(int argc, char** argv
   // Need to prime the host OS version value for linux to prevent IO on the
   // network thread. base::GetLinuxDistro() caches the result.
   base::GetLinuxDistro();
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
   base::File read_file;
   base::File write_file;
@@ -253,7 +253,7 @@ int It2MeNativeMessagingHostMain(int argc, char** argv
   std::unique_ptr<PolicyWatcher> policy_watcher =
       PolicyWatcher::CreateWithTaskRunner(context->file_task_runner());
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // Create an X11EventSource on all UI threads, so the global X11 connection
   // (x11::Connection::Get()) can dispatch X events.
   auto event_source =
@@ -262,7 +262,7 @@ int It2MeNativeMessagingHostMain(int argc, char** argv
   input_task_runner->PostTask(FROM_HERE, base::BindOnce([]() {
                                 new ui::X11EventSource(x11::Connection::Get());
                               }));
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
   std::unique_ptr<extensions::NativeMessageHost> host(
       new It2MeNativeMessagingHost(is_process_elevated_,
@@ -275,11 +275,11 @@ int It2MeNativeMessagingHostMain(int argc, char** argv
   // Run the loop until channel is alive.
   run_loop.Run();
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   input_task_runner->PostTask(FROM_HERE, base::BindOnce([]() {
                                 delete ui::X11EventSource::GetInstance();
                               }));
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
   // Block until tasks blocking shutdown have completed their execution.
   base::ThreadPoolInstance::Get()->Shutdown();
