--- pdns_recursor.cc.orig	2022-12-09 10:46:42 UTC
+++ pdns_recursor.cc
@@ -2517,7 +2517,7 @@ void makeUDPServerSockets(deferredAdd_t& deferredAdds,
     if (g_reusePort) {
 #if defined(SO_REUSEPORT_LB)
       try {
-        SSetsockopt(fd, SOL_SOCKET, SO_REUSEPORT_LB, 1);
+        SSetsockopt(socketFd, SOL_SOCKET, SO_REUSEPORT_LB, 1);
       }
       catch (const std::exception& e) {
         throw PDNSException(std::string("SO_REUSEPORT_LB: ") + e.what());
