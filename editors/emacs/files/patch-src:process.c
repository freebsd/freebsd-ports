--- src/process.c.orig	Mon Mar 17 07:06:56 2003
+++ src/process.c	Tue Aug 12 01:17:12 2003
@@ -1850,6 +1850,7 @@
   for (lres = res; lres; lres = lres->ai_next)
     {
       s = socket (lres->ai_family, lres->ai_socktype, lres->ai_protocol);
+
       if (s < 0)
 	{
 	  xerrno = errno;
@@ -1882,19 +1883,43 @@
 	 It'd be nice to be able to control the connect timeout
 	 though.  Would non-blocking connect calls be portable?  */
       turn_on_atimers (0);
+      
       ret = connect (s, lres->ai_addr, lres->ai_addrlen);
       xerrno = errno;
       turn_on_atimers (1);
 
-      if (ret == 0 || xerrno == EISCONN)
+      if (ret == 0 || xerrno == EISCONN )
 	/* The unwind-protect will be discarded afterwards.
 	   Likewise for immediate_quit.  */
 	break;
 
       immediate_quit = 0;
 
-      if (xerrno == EINTR)
-	goto loop;
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
       if (xerrno == EADDRINUSE && retry < 20)
 	{
 	  /* A delay here is needed on some FreeBSD systems,
@@ -2000,11 +2025,30 @@
       && errno != EISCONN)
     {
       int xerrno = errno;
-
+      
       immediate_quit = 0;
 
-      if (errno == EINTR)
-	goto loop;
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
       if (errno == EADDRINUSE && retry < 20)
 	{
 	  /* A delay here is needed on some FreeBSD systems,
