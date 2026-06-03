--- net/dns/dns_util.cc.orig	2026-03-13 16:54:03 UTC
+++ net/dns/dns_util.cc
@@ -28,6 +28,8 @@
 #include "net/dns/public/util.h"
 #include "net/third_party/uri_template/uri_template.h"
 
+#include <sys/socket.h>
+
 #if BUILDFLAG(IS_POSIX)
 #include <net/if.h>
 #include <netinet/in.h>
