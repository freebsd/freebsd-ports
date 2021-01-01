--- src/Lib/Network/SocketBase.cpp.orig	2016-04-09 13:14:00 UTC
+++ src/Lib/Network/SocketBase.cpp
@@ -147,7 +147,7 @@ SocketBase::bindSocketTo(const Address& toaddr) throw(
 {
     if ( state == CONFIGURED )
     {
-        int res = bind(sockfd, toaddr.getSockaddr(), toaddr.getSockaddrLen());
+        int res = ::bind(sockfd, toaddr.getSockaddr(), toaddr.getSockaddrLen());
         if(res == SOCKET_ERROR) {
             lastError = GET_NET_ERROR();
             doClose();
