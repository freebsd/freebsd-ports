--- content/app/content_main.cc.orig	2021-04-14 01:08:47 UTC
+++ content/app/content_main.cc
@@ -229,7 +229,7 @@ int RunContentProcess(const ContentMainParams& params,
 #endif
     base::EnableTerminationOnOutOfMemory();
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
     // The various desktop environments set this environment variable that
     // allows the dbus client library to connect directly to the bus. When this
     // variable is not set (test environments like xvfb-run), the dbus client
