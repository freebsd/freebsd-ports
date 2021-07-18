--- remoting/host/host_main.cc.orig	2021-04-14 01:08:53 UTC
+++ remoting/host/host_main.cc
@@ -48,9 +48,9 @@ int DesktopProcessMain();
 int FileChooserMain();
 int RdpDesktopSessionMain();
 #endif  // defined(OS_WIN)
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 int XSessionChooserMain();
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 namespace {
 
@@ -61,10 +61,14 @@ const char kUsageMessage[] =
     "\n"
     "Options:\n"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
     "  --audio-pipe-name=<pipe> - Sets the pipe name to capture audio on "
+#if defined(OS_LINUX)
     "Linux.\n"
-#endif  // defined(OS_LINUX)
+#else
+    "FreeBSD.\n"
+#endif
+#endif  // defined(OS_LINUX) || defined(OS_FREEBSD)
 
 #if defined(OS_APPLE)
     "  --list-audio-devices     - List all audio devices and their device "
@@ -152,10 +156,10 @@ MainRoutineFn SelectMainRoutine(const std::string& pro
   } else if (process_type == kProcessTypeRdpDesktopSession) {
     main_routine = &RdpDesktopSessionMain;
 #endif  // defined(OS_WIN)
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   } else if (process_type == kProcessTypeXSessionChooser) {
     main_routine = &XSessionChooserMain;
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   }
 
   return main_routine;
