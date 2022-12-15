--- services/network/network_service.cc.orig	2022-09-24 10:57:32 UTC
+++ services/network/network_service.cc
@@ -83,7 +83,7 @@
 #include "third_party/boringssl/src/include/openssl/cpu.h"
 #endif
 
-#if (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CASTOS)) || \
+#if ((BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CASTOS)) || BUILDFLAG(IS_BSD)) || \
     BUILDFLAG(IS_CHROMEOS_LACROS)
 
 #include "components/os_crypt/key_storage_config_linux.h"
