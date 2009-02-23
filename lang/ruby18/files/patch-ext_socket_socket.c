--- ext/socket/socket.c.orig	2009-02-23 00:54:12.000000000 +0300
+++ ext/socket/socket.c	2009-02-23 01:27:13.000000000 +0300
@@ -1111,81 +1111,33 @@
     fcntl(fd, F_SETFL, mode|NONBLOCKING);
 #endif /* HAVE_FCNTL */
 
-    for (;;) {
 #if defined(SOCKS) && !defined(SOCKS5)
-	if (socks) {
-	    status = Rconnect(fd, sockaddr, len);
-	}
-	else
-#endif
-	{
-	    status = connect(fd, sockaddr, len);
-	}
-	if (status < 0) {
-	    switch (errno) {
-	      case EAGAIN:
-#ifdef EINPROGRESS
-	      case EINPROGRESS:
-#endif
-#if WAIT_IN_PROGRESS > 0
-		sockerrlen = sizeof(sockerr);
-		status = getsockopt(fd, SOL_SOCKET, SO_ERROR, (void *)&sockerr, &sockerrlen);
-		if (status) break;
-		if (sockerr) {
-		    status = -1;
-		    errno = sockerr;
-		    break;
-		}
-#endif
-#ifdef EALREADY
-	      case EALREADY:
-#endif
-#if WAIT_IN_PROGRESS > 0
-		wait_in_progress = WAIT_IN_PROGRESS;
-#endif
-		status = wait_connectable(fd);
-		if (status) {
-		    break;
-		}
-		errno = 0;
-		continue;
-
-#if WAIT_IN_PROGRESS > 0
-	      case EINVAL:
-		if (wait_in_progress-- > 0) {
-		    /*
-		     * connect() after EINPROGRESS returns EINVAL on
-		     * some platforms, need to check true error
-		     * status.
-		     */
-		    sockerrlen = sizeof(sockerr);
-		    status = getsockopt(fd, SOL_SOCKET, SO_ERROR, (void *)&sockerr, &sockerrlen);
-		    if (!status && !sockerr) {
-			struct timeval tv = {0, 100000};
-			rb_thread_wait_for(tv);
-			continue;
-		    }
-		    status = -1;
-		    errno = sockerr;
-		}
-		break;
-#endif
-
-#ifdef EISCONN
-	      case EISCONN:
-		status = 0;
-		errno = 0;
-		break;
+    if (socks) {
+	status = Rconnect(fd, sockaddr, len);
+    }
+    else
 #endif
-	      default:
-		break;
+    {
+	status = connect(fd, sockaddr, len);
+    }
+
+    if (status < 0 && (errno == EINPROGRESS || errno == EWOULDBLOCK)) {
+	status = wait_connectable(fd);
+	if (status == 0) {
+	    int buf;
+	    char c;
+	    int len = sizeof(buf);
+	    status = getpeername(fd, (struct sockaddr *)&buf, &len);
+	    if (status == -1) {
+		read(fd, &c, 1);	/* set errno. */
 	    }
 	}
+    }
+
 #ifdef HAVE_FCNTL
-	fcntl(fd, F_SETFL, mode);
+    fcntl(fd, F_SETFL, mode);
 #endif
-	return status;
-    }
+    return status;
 }
 
 struct inetsock_arg
