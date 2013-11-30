--- src/lib/network.cc.orig
+++ src/lib/network.cc
@@ -6,6 +6,7 @@
 #include <cassert>
 #include <cerrno>
 #include <csignal>
+#include <cstdlib>
 #include <cstring>
 #include <new>
 #include <string>
@@ -289,7 +290,7 @@
 
     set_socket_nonblocking(listenfd);
 
-    sa = (sockaddr*)std::malloc(MAXSOCKADDR);
+    sa = (sockaddr*)malloc(MAXSOCKADDR);
     if (sa == NULL)
         throw std::bad_alloc();
 }
@@ -370,7 +371,7 @@
         const size_t    MIN_POLLFD = 10;
         /* allocate more memory for the pollfd array */
         fd_alloc = std::max(MIN_POLLFD, 3 * fd_alloc / 2);
-        pollfd* tmp = (pollfd*)std::realloc(fds, fd_alloc * sizeof *fds);
+        pollfd* tmp = (pollfd*)realloc(fds, fd_alloc * sizeof *fds);
         if (tmp == NULL)
             throw std::bad_alloc();
