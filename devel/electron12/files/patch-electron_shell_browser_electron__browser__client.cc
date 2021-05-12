--- electron/shell/browser/electron_browser_client.cc.orig	2021-04-20 23:32:33 UTC
+++ electron/shell/browser/electron_browser_client.cc
@@ -169,7 +169,7 @@
 #include "content/public/common/child_process_host.h"
 #endif
 
-#if defined(OS_LINUX) && !defined(MAS_BUILD)
+#if defined(OS_LINUX) && !defined(MAS_BUILD) && !defined(OS_BSD)
 #include "base/debug/leak_annotations.h"
 #include "components/crash/content/browser/crash_handler_host_linux.h"
 #include "components/crash/core/app/breakpad_linux.h"  // nogncheck
