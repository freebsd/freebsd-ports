
$FreeBSD$

--- erts/epmd/src/epmd_srv.c.orig
+++ erts/epmd/src/epmd_srv.c
@@ -736,6 +736,7 @@
   for (i = 0; i < g->max_conn; i++) {
     if (g->conn[i].open == EPMD_FALSE) {
       struct sockaddr_in si;
+      struct sockaddr_in di;
 #ifdef HAVE_SOCKLEN_T
       socklen_t st;
 #else
@@ -756,12 +757,16 @@
       /* Determine if connection is from localhost */
       if (getpeername(s->fd,(struct sockaddr*) &si,&st) ||
 	  st < sizeof(si)) {
-	  /* Failure to get peername is regarder as non local host */
+	  /* Failure to get peername is regarded as non local host */
 	  s->local_peer = EPMD_FALSE;
       } else {
+	  /* Only 127.x.x.x and connections from the host's IP address
+	     allowed, no false positives */
 	  s->local_peer =
-	      ((((unsigned) ntohl(si.sin_addr.s_addr)) & 0xFF000000U) ==
-	       0x7F000000U); /* Only 127.x.x.x allowed, no false positives */
+	      (((((unsigned) ntohl(si.sin_addr.s_addr)) & 0xFF000000U) ==
+	       0x7F000000U) ||
+	       (getsockname(s->fd,(struct sockaddr*) &di,&st) ?
+	       EPMD_FALSE : si.sin_addr.s_addr == di.sin_addr.s_addr));
       }
       dbg_tty_printf(g,2,(s->local_peer) ? "Local peer connected" :
 		     "Non-local peer connected");
