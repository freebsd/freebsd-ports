--- net/dns/dns_util.cc.orig	2021-09-14 01:52:00 UTC
+++ net/dns/dns_util.cc
@@ -28,6 +28,8 @@
 #include "third_party/abseil-cpp/absl/types/optional.h"
 #include "url/url_canon.h"
 
+#include <sys/socket.h>
+
 #if defined(OS_POSIX)
 #include <netinet/in.h>
 #include <net/if.h>
