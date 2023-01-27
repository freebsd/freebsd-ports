--- content/app/content_main.cc.orig	2022-10-24 13:33:33 UTC
+++ content/app/content_main.cc
@@ -226,7 +226,7 @@ RunContentProcess(ContentMainParams params,
 #endif
     base::EnableTerminationOnOutOfMemory();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     // The various desktop environments set this environment variable that
     // allows the dbus client library to connect directly to the bus. When this
     // variable is not set (test environments like xvfb-run), the dbus client
