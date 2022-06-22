--- net/dns/dns_util.cc.orig	2022-05-19 05:17:44 UTC
+++ net/dns/dns_util.cc
@@ -27,6 +27,8 @@
 #include "net/third_party/uri_template/uri_template.h"
 #include "third_party/abseil-cpp/absl/types/optional.h"
 
+#include <sys/socket.h>
+
 #if BUILDFLAG(IS_POSIX)
 #include <netinet/in.h>
 #include <net/if.h>
