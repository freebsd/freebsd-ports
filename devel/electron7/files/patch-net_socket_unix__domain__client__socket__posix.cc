--- net/socket/unix_domain_client_socket_posix.cc.orig	2019-12-12 12:39:54 UTC
+++ net/socket/unix_domain_client_socket_posix.cc
@@ -56,7 +56,7 @@ bool UnixDomainClientSocket::FillAddress(const std::st
     return true;
   }
 
-#if defined(OS_ANDROID) || defined(OS_LINUX)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD)
   // Convert the path given into abstract socket name. It must start with
   // the '\0' character, so we are adding it. |addr_len| must specify the
   // length of the structure exactly, as potentially the socket name may
