--- commoncpp/socket.cpp.orig	2011-06-01 09:52:54.000000000 +0000
+++ commoncpp/socket.cpp	2011-06-01 09:52:10.000000000 +0000
@@ -108,7 +108,7 @@
 }
 # define DUP_SOCK(s,state) dupSocket(s,state)
 #else
-socket_t Socket::dupSocket(socket_t so, enum Socket::State state)
+socket_t Socket::dupSocket(socket_t so, Socket::State state)
 {
     return dup(so);
 }
