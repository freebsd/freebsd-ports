--- src/lib/server.h.orig	2009-10-09 19:08:47.000000000 +0900
+++ src/lib/server.h	2010-05-30 04:29:46.123851884 +0900
@@ -19,6 +19,10 @@
 #include <sys/epoll.h>
 #endif
 
+#ifdef HAVE_KQUEUE
+#include <sys/event.h>
+#endif
+
 #include "connection.h"
 
 namespace gree {
@@ -40,6 +44,9 @@
 #ifdef HAVE_EPOLL
 	int		_epoll_socket;
 #endif
+#ifdef HAVE_KQUEUE
+	int		_kqueue_socket;
+#endif
 	int		_back_log;
 
 public:
@@ -59,6 +66,9 @@
 #ifdef HAVE_EPOLL
 	int _add_epoll_socket(int sock);
 #endif
+#ifdef HAVE_KQUEUE
+	int	_add_kqueue_socket(int sock);
+#endif
 };
 
 }	// namespace flare
