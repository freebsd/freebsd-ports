--- content/app/content_main.cc.orig	2026-08-19 23:17:14 UTC
+++ content/app/content_main.cc
@@ -236,7 +236,7 @@ NO_STACK_PROTECTOR int RunContentProcess(
     base::EnableTerminationOnOutOfMemory();
     logging::RegisterAbslAbortHook();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     // The various desktop environments set this environment variable that
     // allows the dbus client library to connect directly to the bus. When this
     // variable is not set (test environments like xvfb-run), the dbus client
@@ -330,7 +330,7 @@ NO_STACK_PROTECTOR int RunContentProcess(
 #endif
 #endif
 
-#if (BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)) && !defined(COMPONENT_BUILD)
+#if (BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)) && !defined(COMPONENT_BUILD) && defined(notyet)
     base::subtle::EnableFDOwnershipEnforcement(true);
 #endif
 
