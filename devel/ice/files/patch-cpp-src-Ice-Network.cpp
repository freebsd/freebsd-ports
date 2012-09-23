--- cpp.orig/src/Ice/Network.cpp	2011-06-15 21:43:58.000000000 +0200
+++ cpp/src/Ice/Network.cpp	2012-09-10 11:43:58.000000000 +0200
@@ -715,7 +715,11 @@
     WSASetLastError(error);
 #else
     int error = errno;
-    if(close(fd) == SOCKET_ERROR)
+    if(close(fd) == SOCKET_ERROR
+#  if defined(__FreeBSD__)
+    && getSocketErrno() != ECONNRESET
+#  endif
+    )
     {
         SocketException ex(__FILE__, __LINE__);
         ex.error = getSocketErrno();
@@ -1098,7 +1098,7 @@ IceInternal::doBind(SOCKET fd, const struct sockaddr_storage& addr)
         size = 0; // Keep the compiler happy.
     }
 
-    if(bind(fd, reinterpret_cast<const struct sockaddr*>(&addr), size) == SOCKET_ERROR)
+    if(::bind(fd, reinterpret_cast<const struct sockaddr*>(&addr), size) == SOCKET_ERROR)
     {
         closeSocketNoThrow(fd);
         SocketException ex(__FILE__, __LINE__);
