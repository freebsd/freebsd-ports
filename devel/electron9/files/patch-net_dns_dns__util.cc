--- net/dns/dns_util.cc.orig	2020-05-26 07:48:33 UTC
+++ net/dns/dns_util.cc
@@ -39,6 +39,8 @@ const uint16_t kFlagNamePointer = 0xc000;
 
 }  // namespace
 
+#include <sys/socket.h>
+
 #if defined(OS_POSIX)
 #include <netinet/in.h>
 #if !defined(OS_NACL)
