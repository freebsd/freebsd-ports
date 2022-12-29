--- rec-tcp.cc.orig	2022-12-09 10:46:42 UTC
+++ rec-tcp.cc
@@ -1067,7 +1067,7 @@ void makeTCPServerSockets(deferredAdd_t& deferredAdds,
     if (g_reusePort) {
 #if defined(SO_REUSEPORT_LB)
       try {
-        SSetsockopt(fd, SOL_SOCKET, SO_REUSEPORT_LB, 1);
+        SSetsockopt(socketFd, SOL_SOCKET, SO_REUSEPORT_LB, 1);
       }
       catch (const std::exception& e) {
         throw PDNSException(std::string("SO_REUSEPORT_LB: ") + e.what());
