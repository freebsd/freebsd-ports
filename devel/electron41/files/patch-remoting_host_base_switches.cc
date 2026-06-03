--- remoting/host/base/switches.cc.orig	2026-03-13 16:54:03 UTC
+++ remoting/host/base/switches.cc
@@ -24,13 +24,13 @@ const char kProcessTypeUrlForwarderConfigurator[] =
 const char kProcessTypeFileChooser[] = "file_chooser";
 const char kProcessTypeUrlForwarderConfigurator[] =
     "url_forwarder_configurator";
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const char kProcessTypeXSessionChooser[] = "xsession_chooser";
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
 const char kEvaluateCapabilitySwitchName[] = "evaluate-type";
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const char kEnableWtmpdb[] = "enable-wtmpdb";
 #endif
 
