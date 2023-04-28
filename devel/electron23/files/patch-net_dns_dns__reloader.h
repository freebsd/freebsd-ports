--- net/dns/dns_reloader.h.orig	2022-11-30 08:12:58 UTC
+++ net/dns/dns_reloader.h
@@ -7,7 +7,7 @@
 
 #include "build/build_config.h"
 
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_OPENBSD)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_BSD)
 namespace net {
 
 // Call on the network thread before calling DnsReloaderMaybeReload() anywhere.
@@ -18,6 +18,6 @@ void EnsureDnsReloaderInit();
 void DnsReloaderMaybeReload();
 
 }  // namespace net
-#endif  // BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_OPENBSD)
+#endif  // BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_APPLE)
 
 #endif  // NET_DNS_DNS_RELOADER_H_
