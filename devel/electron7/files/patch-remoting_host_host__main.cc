--- remoting/host/host_main.cc.orig	2019-12-12 12:39:55 UTC
+++ remoting/host/host_main.cc
@@ -49,9 +49,9 @@ int DesktopProcessMain();
 int FileChooserMain();
 int RdpDesktopSessionMain();
 #endif  // defined(OS_WIN)
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 int XSessionChooserMain();
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 namespace {
 
@@ -146,10 +146,10 @@ MainRoutineFn SelectMainRoutine(const std::string& pro
   } else if (process_type == kProcessTypeRdpDesktopSession) {
     main_routine = &RdpDesktopSessionMain;
 #endif  // defined(OS_WIN)
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   } else if (process_type == kProcessTypeXSessionChooser) {
     main_routine = &XSessionChooserMain;
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
   }
 
   return main_routine;
