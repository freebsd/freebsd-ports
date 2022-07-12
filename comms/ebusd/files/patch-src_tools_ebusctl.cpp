--- src/tools/ebusctl.cpp.orig	2022-07-12 13:01:34 UTC
+++ src/tools/ebusctl.cpp
@@ -147,7 +147,13 @@ string fetchData(ebusd::TCPSocket* socket, bool &liste
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
 
