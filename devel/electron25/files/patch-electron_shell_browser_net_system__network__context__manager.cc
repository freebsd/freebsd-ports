--- electron/shell/browser/net/system_network_context_manager.cc.orig	2023-08-09 14:05:20 UTC
+++ electron/shell/browser/net/system_network_context_manager.cc
@@ -41,7 +41,7 @@
 #include "shell/common/options_switches.h"
 #include "url/gurl.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "components/os_crypt/sync/key_storage_config_linux.h"
 #endif
 
