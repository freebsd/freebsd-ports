--- electron/shell/browser/electron_browser_client.cc.orig	2022-08-03 15:31:32 UTC
+++ electron/shell/browser/electron_browser_client.cc
@@ -184,7 +184,7 @@
 #include "content/public/common/child_process_host.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) && !defined(MAS_BUILD)
+#if BUILDFLAG(IS_LINUX) && !defined(MAS_BUILD) && !BUILDFLAG(IS_BSD)
 #include "base/debug/leak_annotations.h"
 #include "components/crash/content/browser/crash_handler_host_linux.h"
 #include "components/crash/core/app/breakpad_linux.h"  // nogncheck
