--- src/tools/ebusctl.cpp.orig	2023-07-08 13:54:20 UTC
+++ src/tools/ebusctl.cpp
@@ -153,7 +153,13 @@ string fetchData(ebusd::TCPSocket* socket, bool &liste
   time_t now;
   time(&now);
   time_t endTime = now + timeout;
+
 #ifdef HAVE_PPOLL
+
+#ifndef POLLRDHUP
+#  define POLLRDHUP 0
+#endif
+
   int nfds = 2;
   struct pollfd fds[nfds];
 
