--- net/dns/dns_util.cc.orig	2019-09-10 11:14:09 UTC
+++ net/dns/dns_util.cc
@@ -36,6 +36,8 @@ const uint16_t kFlagNamePointer = 0xc000;
 
 }  // namespace
 
+#include <sys/socket.h>
+
 #if defined(OS_POSIX)
 #include <netinet/in.h>
 #if !defined(OS_NACL)
