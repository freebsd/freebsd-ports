--- electron/shell/browser/net/system_network_context_manager.cc.orig	2024-10-22 02:29:46 UTC
+++ electron/shell/browser/net/system_network_context_manager.cc
@@ -40,7 +40,7 @@
 #include "shell/common/options_switches.h"
 #include "url/gurl.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "components/os_crypt/sync/key_storage_config_linux.h"
 #endif
 
