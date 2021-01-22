--- remoting/host/switches.h.orig	2020-05-26 08:03:25 UTC
+++ remoting/host/switches.h
@@ -34,9 +34,9 @@ extern const char kProcessTypeHost[];
 extern const char kProcessTypeRdpDesktopSession[];
 extern const char kProcessTypeEvaluateCapability[];
 extern const char kProcessTypeFileChooser[];
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 extern const char kProcessTypeXSessionChooser[];
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 extern const char kEvaluateCapabilitySwitchName[];
 
