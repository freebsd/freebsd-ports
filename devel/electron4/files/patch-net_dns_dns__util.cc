--- net/dns/dns_util.cc.orig	2019-03-15 06:37:29 UTC
+++ net/dns/dns_util.cc
@@ -28,6 +28,8 @@ const int kMaxLabelLength = 63;
 
 }  // namespace
 
+#include <sys/socket.h>
+
 #if defined(OS_POSIX)
 #include <netinet/in.h>
 #if !defined(OS_NACL)
