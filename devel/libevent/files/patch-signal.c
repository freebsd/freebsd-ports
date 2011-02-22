--- signal.c.orig	2011-02-22 09:41:14.711661986 +0100
+++ signal.c	2011-02-22 09:41:52.113522401 +0100
@@ -67,6 +67,13 @@
 
 static void evsignal_handler(int sig);
 
+#ifdef WIN32
+#define error_is_eagain(err)			\
+	((err) == EAGAIN || (err) == WSAEWOULDBLOCK)
+#else
+#define error_is_eagain(err) ((err) == EAGAIN)
+#endif
+
 /* Callback for when the signal handler write a byte to our signaling socket */
 static void
 evsignal_cb(int fd, short what, void *arg)
@@ -79,8 +86,11 @@
 #endif
 
 	n = recv(fd, signals, sizeof(signals), 0);
-	if (n == -1)
-		event_err(1, "%s: read", __func__);
+	if (n == -1) {
+		int err = EVUTIL_SOCKET_ERROR();
+		if (! error_is_eagain(err))
+			event_err(1, "%s: read", __func__);
+	}
 }
 
 #ifdef HAVE_SETFD
@@ -125,6 +135,7 @@
 		TAILQ_INIT(&base->sig.evsigevents[i]);
 
         evutil_make_socket_nonblocking(base->sig.ev_signal_pair[0]);
+        evutil_make_socket_nonblocking(base->sig.ev_signal_pair[1]);
 
 	event_set(&base->sig.ev_signal, base->sig.ev_signal_pair[1],
 		EV_READ | EV_PERSIST, evsignal_cb, &base->sig.ev_signal);
