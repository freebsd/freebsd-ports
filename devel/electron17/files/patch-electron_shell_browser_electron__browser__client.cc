--- electron/shell/browser/electron_browser_client.cc.orig	2022-05-11 15:32:29 UTC
+++ electron/shell/browser/electron_browser_client.cc
@@ -179,7 +179,7 @@
 #include "content/public/common/child_process_host.h"
 #endif
 
-#if defined(OS_LINUX) && !defined(MAS_BUILD)
+#if defined(OS_LINUX) && !defined(MAS_BUILD) && !defined(OS_BSD)
 #include "base/debug/leak_annotations.h"
 #include "components/crash/content/browser/crash_handler_host_linux.h"
 #include "components/crash/core/app/breakpad_linux.h"  // nogncheck
