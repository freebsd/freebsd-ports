--- electron/shell/browser/net/system_network_context_manager.cc.orig	2025-03-26 14:46:58 UTC
+++ electron/shell/browser/net/system_network_context_manager.cc
@@ -39,7 +39,7 @@
 #include "shell/common/options_switches.h"
 #include "url/gurl.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "components/os_crypt/sync/key_storage_config_linux.h"
 #endif
 
