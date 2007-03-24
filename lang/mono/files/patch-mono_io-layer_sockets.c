--- mono/io-layer/sockets.c	2007/01/11 13:28:29	70852
+++ mono/io-layer/sockets.c	2007/03/22 14:59:57	74811
@@ -15,6 +15,7 @@
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/ioctl.h>
+#include <sys/poll.h>
 #ifdef HAVE_SYS_FILIO_H
 #include <sys/filio.h>     /* defines FIONBIO and FIONREAD */
 #endif
@@ -272,7 +273,8 @@
 		  socklen_t addrlen)
 {
 	gpointer handle = GUINT_TO_POINTER (fd);
-	int ret;
+	struct _WapiHandle_socket *socket_handle;
+	gboolean ok;
 	gint errnum;
 	
 	if (startup_count == 0) {
@@ -285,26 +287,82 @@
 		return(SOCKET_ERROR);
 	}
 	
-	do {
-		ret = connect (fd, serv_addr, addrlen);
-	} while (ret==-1 && errno==EINTR && !_wapi_thread_cur_apc_pending());
-
-	if (ret == -1) {
+	if (connect (fd, serv_addr, addrlen) == -1) {
+		struct pollfd fds;
+		int so_error;
+		socklen_t len;
+		
 		errnum = errno;
 		
+		if (errno != EINTR) {
 #ifdef DEBUG
-		g_message ("%s: connect error: %s", __func__,
-			   strerror (errnum));
+			g_message ("%s: connect error: %s", __func__,
+				   strerror (errnum));
 #endif
-		errnum = errno_to_WSA (errnum, __func__);
-		if (errnum == WSAEINPROGRESS)
-			errnum = WSAEWOULDBLOCK; /* see bug #73053 */
 
-		WSASetLastError (errnum);
+			errnum = errno_to_WSA (errnum, __func__);
+			if (errnum == WSAEINPROGRESS)
+				errnum = WSAEWOULDBLOCK; /* see bug #73053 */
+
+			WSASetLastError (errnum);
 		
-		return(SOCKET_ERROR);
+			return(SOCKET_ERROR);
+		}
+
+		fds.fd = fd;
+		fds.events = POLLOUT;
+		while (poll (&fds, 1, -1) == -1 &&
+		       !_wapi_thread_cur_apc_pending ()) {
+			if (errno != EINTR) {
+				errnum = errno_to_WSA (errno, __func__);
+
+#ifdef DEBUG
+				g_message ("%s: connect poll error: %s",
+					   __func__, strerror (errno));
+#endif
+
+				WSASetLastError (errnum);
+				return(SOCKET_ERROR);
+			}
+		}
+
+		len = sizeof(so_error);
+		if (getsockopt (fd, SOL_SOCKET, SO_ERROR, &so_error,
+				&len) == -1) {
+			errnum = errno_to_WSA (errno, __func__);
+
+#ifdef DEBUG
+			g_message ("%s: connect getsockopt error: %s",
+				   __func__, strerror (errno));
+#endif
+
+			WSASetLastError (errnum);
+			return(SOCKET_ERROR);
+		}
+		
+		if (so_error != 0) {
+			errnum = errno_to_WSA (so_error, __func__);
+
+			/* Need to save this socket error */
+			ok = _wapi_lookup_handle (handle, WAPI_HANDLE_SOCKET,
+						  (gpointer *)&socket_handle);
+			if (ok == FALSE) {
+				g_warning ("%s: error looking up socket handle %p", __func__, handle);
+			} else {
+				socket_handle->saved_error = errnum;
+			}
+			
+#ifdef DEBUG
+			g_message ("%s: connect getsockopt returned error: %s",
+				   __func__, strerror (so_error));
+#endif
+
+			WSASetLastError (errnum);
+			return(SOCKET_ERROR);
+		}
 	}
-	return(ret);
+		
+	return(0);
 }
 
 int _wapi_getpeername(guint32 fd, struct sockaddr *name, socklen_t *namelen)
@@ -378,7 +436,9 @@
 	int ret;
 	struct timeval tv;
 	void *tmp_val;
-
+	struct _WapiHandle_socket *socket_handle;
+	gboolean ok;
+	
 	if (startup_count == 0) {
 		WSASetLastError (WSANOTINITIALISED);
 		return(SOCKET_ERROR);
@@ -415,9 +475,23 @@
 	}
 
 	if (optname == SO_ERROR) {
-		if (*((int *)optval) != 0) {
+		ok = _wapi_lookup_handle (handle, WAPI_HANDLE_SOCKET,
+					  (gpointer *)&socket_handle);
+		if (ok == FALSE) {
+			g_warning ("%s: error looking up socket handle %p",
+				   __func__, handle);
+
+			/* can't extract the last error */
 			*((int *) optval) = errno_to_WSA (*((int *)optval),
 							  __func__);
+		} else {
+			if (*((int *)optval) != 0) {
+				*((int *) optval) = errno_to_WSA (*((int *)optval),
+								  __func__);
+				socket_handle->saved_error = *((int *)optval);
+			} else {
+				*((int *)optval) = socket_handle->saved_error;
+			}
 		}
 	}
 	
