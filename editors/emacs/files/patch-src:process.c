--- src/process.c.orig	Mon Mar 17 07:06:56 2003
+++ src/process.c	Fri Apr 23 19:28:58 2004
@@ -1891,10 +1891,34 @@
 	   Likewise for immediate_quit.  */
 	break;
 
+#if 1
+      if ( (errno == EINTR ) || (errno == EINPROGRESS)){
+	fd_set fds;
+	int e;
+	struct timeval tv;
+	tv.tv_sec =60;
+	tv.tv_usec = 0;
+	FD_ZERO(&fds);
+	FD_SET(s, &fds);
+      resel:
+        QUIT;
+	e = select(s+1, NULL, &fds, NULL, &tv);
+
+	if( e == -1){
+	  if(errno == EINTR)
+	    goto resel;
+	  else
+	    xerrno = ETIMEDOUT;
+	}
+	else {
+	  xerrno = 0;
+	  break;
+	}
+      }
+#endif
+
       immediate_quit = 0;
 
-      if (xerrno == EINTR)
-	goto loop;
       if (xerrno == EADDRINUSE && retry < 20)
 	{
 	  /* A delay here is needed on some FreeBSD systems,
@@ -2001,10 +2025,30 @@
     {
       int xerrno = errno;
 
+#if 1
+      if ( (errno == EINTR ) || (errno == EINPROGRESS)){
+	fd_set fds;
+	int e;
+	struct timeval tv;
+	tv.tv_sec =60;
+	tv_tv_usec = 0;
+	FD_CLEAR(&fds);
+	FD_SET(s, &fds);
+      resel:
+        QUIT;
+	e = select(s+1, NULL, fds, NULL, &tv);
+	if( e != 0){
+	  if(errno == EINTR)
+	    goto resel;
+	  else
+	    xerrno = ETIMEDOUT;
+	}
+	else 
+	  xerrno = 0;
+      }
+#endif
       immediate_quit = 0;
 
-      if (errno == EINTR)
-	goto loop;
       if (errno == EADDRINUSE && retry < 20)
 	{
 	  /* A delay here is needed on some FreeBSD systems,
