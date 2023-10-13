--- util/netevent.c.orig	2023-08-30 01:01:13.000000000 -0700
+++ util/netevent.c	2023-10-12 19:00:53.157995000 -0700
@@ -116,6 +116,8 @@
 
 /** timeout in millisec to wait for write to unblock, packets dropped after.*/
 #define SEND_BLOCKED_WAIT_TIMEOUT 200
+/** max number of times to wait for write to unblock, packets dropped after.*/
+#define SEND_BLOCKED_MAX_RETRY 5
 
 /** Let's make timestamping code cleaner and redefine SO_TIMESTAMP* */
 #ifndef SO_TIMESTAMP
@@ -402,9 +404,10 @@
 			WSAGetLastError() == WSAENOBUFS ||
 			WSAGetLastError() == WSAEWOULDBLOCK) {
 #endif
+			int retries = 0;
 			/* if we set the fd blocking, other threads suddenly
 			 * have a blocking fd that they operate on */
-			while(sent == -1 && (
+			while(sent == -1 && retries < SEND_BLOCKED_MAX_RETRY && (
 #ifndef USE_WINSOCK
 				errno == EAGAIN || errno == EINTR ||
 #  ifdef EWOULDBLOCK
@@ -419,6 +422,13 @@
 #endif
 			)) {
 #if defined(HAVE_POLL) || defined(USE_WINSOCK)
+				int send_nobufs = (
+#ifndef USE_WINSOCK
+					errno == ENOBUFS
+#else
+					WSAGetLastError() == WSAENOBUFS
+#endif
+				);
 				struct pollfd p;
 				int pret;
 				memset(&p, 0, sizeof(p));
@@ -457,8 +467,48 @@
 					log_err("poll udp out failed: %s",
 						sock_strerror(errno));
 					return 0;
+				} else if((pret < 0 &&
+#ifndef USE_WINSOCK
+					errno == ENOBUFS
+#else
+					WSAGetLastError() == WSAENOBUFS
+#endif
+					) || (send_nobufs && retries > 0)) {
+					/* ENOBUFS, and poll returned without
+					 * a timeout. Or the retried send call
+					 * returned ENOBUFS. It is good to
+					 * wait a bit for the error to clear. */
+					/* The timeout is 20*(2^(retries+1)),
+					 * it increases exponentially, starting
+					 * at 40 msec. After 5 tries, 1240 msec
+					 * have passed in total, when poll
+					 * returned the error, and 1200 msec
+					 * when send returned the errors. */
+#ifndef USE_WINSOCK
+					pret = poll(NULL, 0, (SEND_BLOCKED_WAIT_TIMEOUT/10)<<(retries+1));
+#else
+					pret = WSAPoll(NULL, 0, (SEND_BLOCKED_WAIT_TIMEOUT/10)<<(retries+1));
+#endif
+					if(pret < 0 &&
+#ifndef USE_WINSOCK
+						errno != EAGAIN && errno != EINTR &&
+#  ifdef EWOULDBLOCK
+						errno != EWOULDBLOCK &&
+#  endif
+						errno != ENOBUFS
+#else
+						WSAGetLastError() != WSAEINPROGRESS &&
+						WSAGetLastError() != WSAEINTR &&
+						WSAGetLastError() != WSAENOBUFS &&
+						WSAGetLastError() != WSAEWOULDBLOCK
+#endif
+					) {
+						log_err("poll udp out timer failed: %s",
+							sock_strerror(errno));
+					}
 				}
 #endif /* defined(HAVE_POLL) || defined(USE_WINSOCK) */
+				retries++;
 				if (!is_connected) {
 					sent = sendto(c->fd, (void*)sldns_buffer_begin(packet),
 						sldns_buffer_remaining(packet), 0,
@@ -665,7 +715,8 @@
 			WSAGetLastError() == WSAENOBUFS ||
 			WSAGetLastError() == WSAEWOULDBLOCK) {
 #endif
-			while(sent == -1 && (
+			int retries = 0;
+			while(sent == -1 && retries < SEND_BLOCKED_MAX_RETRY && (
 #ifndef USE_WINSOCK
 				errno == EAGAIN || errno == EINTR ||
 #  ifdef EWOULDBLOCK
@@ -680,6 +731,13 @@
 #endif
 			)) {
 #if defined(HAVE_POLL) || defined(USE_WINSOCK)
+				int send_nobufs = (
+#ifndef USE_WINSOCK
+					errno == ENOBUFS
+#else
+					WSAGetLastError() == WSAENOBUFS
+#endif
+				);
 				struct pollfd p;
 				int pret;
 				memset(&p, 0, sizeof(p));
@@ -718,8 +776,48 @@
 					log_err("poll udp out failed: %s",
 						sock_strerror(errno));
 					return 0;
+				} else if((pret < 0 &&
+#ifndef USE_WINSOCK
+					errno == ENOBUFS
+#else
+					WSAGetLastError() == WSAENOBUFS
+#endif
+					) || (send_nobufs && retries > 0)) {
+					/* ENOBUFS, and poll returned without
+					 * a timeout. Or the retried send call
+					 * returned ENOBUFS. It is good to
+					 * wait a bit for the error to clear. */
+					/* The timeout is 20*(2^(retries+1)),
+					 * it increases exponentially, starting
+					 * at 40 msec. After 5 tries, 1240 msec
+					 * have passed in total, when poll
+					 * returned the error, and 1200 msec
+					 * when send returned the errors. */
+#ifndef USE_WINSOCK
+					pret = poll(NULL, 0, (SEND_BLOCKED_WAIT_TIMEOUT/10)<<(retries+1));
+#else
+					pret = WSAPoll(NULL, 0, (SEND_BLOCKED_WAIT_TIMEOUT/10)<<(retries+1));
+#endif
+					if(pret < 0 &&
+#ifndef USE_WINSOCK
+						errno != EAGAIN && errno != EINTR &&
+#  ifdef EWOULDBLOCK
+						errno != EWOULDBLOCK &&
+#  endif
+						errno != ENOBUFS
+#else
+						WSAGetLastError() != WSAEINPROGRESS &&
+						WSAGetLastError() != WSAEINTR &&
+						WSAGetLastError() != WSAENOBUFS &&
+						WSAGetLastError() != WSAEWOULDBLOCK
+#endif
+					) {
+						log_err("poll udp out timer failed: %s",
+							sock_strerror(errno));
+					}
 				}
 #endif /* defined(HAVE_POLL) || defined(USE_WINSOCK) */
+				retries++;
 				sent = sendmsg(c->fd, &msg, 0);
 			}
 		}
