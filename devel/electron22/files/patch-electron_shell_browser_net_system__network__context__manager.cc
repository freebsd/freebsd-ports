--- electron/shell/browser/net/system_network_context_manager.cc.orig	2023-01-24 16:58:16 UTC
+++ electron/shell/browser/net/system_network_context_manager.cc
@@ -42,7 +42,7 @@
 #include "shell/common/options_switches.h"
 #include "url/gurl.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "components/os_crypt/key_storage_config_linux.h"
 #endif
 
