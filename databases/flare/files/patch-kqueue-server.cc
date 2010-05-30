--- src/lib/server.cc.orig	2009-10-09 19:08:47.000000000 +0900
+++ src/lib/server.cc	2010-05-30 06:10:23.363742550 +0900
@@ -21,6 +21,9 @@
 #ifdef HAVE_EPOLL
 		_epoll_socket(0),
 #endif
+#ifdef HAVE_KQUEUE
+		_kqueue_socket(-1),
+#endif
 		_back_log(SOMAXCONN) {
 }
 
@@ -55,6 +58,14 @@
 	}
 #endif
 
+#ifdef HAVE_KQUEUE
+	if (this->_kqueue_socket >= 0) {
+		if (::close(this->_kqueue_socket) < 0) {
+			log_err("close() failed: %s (%d) (sock=kqueue)", util::strerror(errno), errno);
+		}
+	}
+#endif
+
 	for (int i = 0; i < this->_listen_socket_index; i++) {
 		int sock = this->_listen_socket[i];
 
@@ -139,6 +150,12 @@
 	}
 #endif
 
+#ifdef HAVE_KQUEUE
+	if (this->_add_kqueue_socket(sock) < 0) {
+		return -1;
+	}
+#endif
+
 	return 0;
 }
 
@@ -195,6 +212,12 @@
 	}
 #endif
 
+#ifdef HAVE_KQUEUE
+	if (this->_add_kqueue_socket(sock) < 0) {
+		return -1;
+	}
+#endif
+
 	return 0;
 }
 
@@ -208,6 +231,10 @@
 	const char* poll_type = "epoll_wait";		// just for logging
 	struct epoll_event ev_list[this->max_listen_socket];
 	int n = epoll_wait(this->_epoll_socket, ev_list, this->max_listen_socket, -1);
+#elifdef HAVE_KQUEUE
+	const char* poll_type = "kqueue_wait";		// just for logging
+	struct kevent kev;
+	int n = kevent(this->_kqueue_socket, &kev, 1, NULL, 0, NULL);
 #else
 	const char* poll_type = "select";		// just for logging
 	fd_set fds;
@@ -230,6 +257,8 @@
 #ifdef HAVE_EPOLL
 	for (int i = 0; i < n; i++) {
 		int listen_socket = ev_list[i].data.fd;
+#elifdef HAVE_KQUEUE
+		int listen_socket = kev.ident;
 #else
 	for (int i = 0; i < this->_listen_socket_index; i++) {
 		if (!FD_ISSET(this->_listen_socket[i], &fds)) {
@@ -369,6 +398,32 @@
 	return 0;
 }
 #endif
+
+#ifdef HAVE_KQUEUE
+/**
+ *  add listen socket to kqueue
+ */
+int server::_add_kqueue_socket(int sock) {
+	if (this->_kqueue_socket <= 0) {
+		this->_kqueue_socket = kqueue();
+		if (this->_kqueue_socket < 0) {
+			log_err("kqueue() failed: %s (%s)", util::strerror(errno), errno);
+			return -1;
+		}
+	}
+
+	struct kevent kev;
+	EV_SET(&kev, sock, EVFILT_READ, EV_ADD, 0, 0, NULL);
+	if (kevent(this->_kqueue_socket, &kev, 1, NULL, 0, NULL) < 0 ) {
+		log_err("kevent() failed: %s (%d) (sock=%d)", util::strerror(errno), errno, sock);
+		return -1;
+	} else {
+		log_debug("added listen socket to kevent (kqueue_socket=%d, listen_socket=%d)", this->_kqueue_socket, sock);
+	}
+
+	return 0;
+}
+#endif
 // }}}
 
 // {{{ private methods
