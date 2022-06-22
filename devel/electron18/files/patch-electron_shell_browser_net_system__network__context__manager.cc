--- electron/shell/browser/net/system_network_context_manager.cc.orig	2022-05-18 15:31:32 UTC
+++ electron/shell/browser/net/system_network_context_manager.cc
@@ -46,7 +46,7 @@
 #include "components/os_crypt/keychain_password_mac.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "components/os_crypt/key_storage_config_linux.h"
 #endif
 
