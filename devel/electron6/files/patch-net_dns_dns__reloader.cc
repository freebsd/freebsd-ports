--- net/dns/dns_reloader.cc.orig	2019-09-10 11:14:09 UTC
+++ net/dns/dns_reloader.cc
@@ -7,6 +7,10 @@
 #if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_OPENBSD) && \
     !defined(OS_ANDROID) && !defined(OS_FUCHSIA)
 
+#if defined(OS_FREEBSD)
+#include <netinet/in.h>
+#endif
+
 #include <resolv.h>
 
 #include "base/lazy_instance.h"
