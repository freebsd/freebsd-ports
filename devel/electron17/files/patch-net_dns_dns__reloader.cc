--- net/dns/dns_reloader.cc.orig	2022-05-11 07:16:53 UTC
+++ net/dns/dns_reloader.cc
@@ -4,7 +4,7 @@
 
 #include "net/dns/dns_reloader.h"
 
-#if defined(OS_POSIX) && !defined(OS_APPLE) && !defined(OS_OPENBSD) && \
+#if defined(OS_POSIX) && !defined(OS_APPLE) && !defined(OS_BSD) && \
     !defined(OS_ANDROID) && !defined(OS_FUCHSIA)
 
 #include <resolv.h>
@@ -111,5 +111,5 @@ void DnsReloaderMaybeReload() {
 
 }  // namespace net
 
-#endif  // defined(OS_POSIX) && !defined(OS_APPLE) && !defined(OS_OPENBSD) &&
+#endif  // defined(OS_POSIX) && !defined(OS_APPLE) && !defined(OS_BSD) &&
         // !defined(OS_ANDROID)
