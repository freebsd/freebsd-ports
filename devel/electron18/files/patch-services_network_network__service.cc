--- services/network/network_service.cc.orig	2022-05-19 05:17:45 UTC
+++ services/network/network_service.cc
@@ -82,7 +82,7 @@
 #include "third_party/boringssl/src/include/openssl/cpu.h"
 #endif
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) && \
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)) && \
     !BUILDFLAG(IS_CHROMECAST)
 #include "components/os_crypt/key_storage_config_linux.h"
 #endif
