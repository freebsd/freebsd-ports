--- cpp.orig/src/Ice/Network.cpp	2013-03-11 15:19:46.000000000 +0000
+++ cpp/src/Ice/Network.cpp	2013-05-19 22:55:40.257195813 +0000
@@ -936,7 +936,11 @@
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
