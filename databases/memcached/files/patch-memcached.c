--- memcached.c.orig	2014-10-13 03:33:10.000000000 +0000
+++ memcached.c	2015-01-16 16:21:34.000000000 +0000
@@ -280,7 +280,7 @@
     c->msgbytes = 0;
     c->msgused++;
 
-    if (IS_UDP(c->transport)) {
+    if IS_UDP(c->transport) {
         /* Leave room for the UDP header, which we'll fill in later. */
         return add_iov(c, NULL, UDP_HEADER_SIZE);
     }
@@ -424,7 +424,7 @@
         if (init_state == conn_listening) {
             fprintf(stderr, "<%d server listening (%s)\n", sfd,
                 prot_text(c->protocol));
-        } else if (IS_UDP(transport)) {
+        } else if IS_UDP(transport) {
             fprintf(stderr, "<%d server listening (udp)\n", sfd);
         } else if (c->protocol == negotiating_prot) {
             fprintf(stderr, "<%d new auto-negotiating client connection\n",
@@ -523,7 +523,7 @@
         c->sasl_conn = NULL;
     }
 
-    if (IS_UDP(c->transport)) {
+    if IS_UDP(c->transport) {
         conn_set_state(c, conn_read);
     }
 }
@@ -593,7 +593,7 @@
 static void conn_shrink(conn *c) {
     assert(c != NULL);
 
-    if (IS_UDP(c->transport))
+    if IS_UDP(c->transport)
         return;
 
     if (c->rsize > READ_BUFFER_HIGHWAT && c->rbytes < DATA_BUFFER_SIZE) {
@@ -3989,7 +3989,7 @@
         if (settings.verbose > 0)
             perror("Failed to write, and not due to blocking");
 
-        if (IS_UDP(c->transport))
+        if IS_UDP(c->transport)
             conn_set_state(c, conn_read);
         else
             conn_set_state(c, conn_closing);
@@ -4313,7 +4313,7 @@
             break;
 
         case conn_closing:
-            if (IS_UDP(c->transport))
+            if IS_UDP(c->transport)
                 conn_cleanup(c);
             else
                 conn_close(c);
@@ -4473,7 +4473,7 @@
 #endif
 
         setsockopt(sfd, SOL_SOCKET, SO_REUSEADDR, (void *)&flags, sizeof(flags));
-        if (IS_UDP(transport)) {
+        if IS_UDP(transport) {
             maximize_sndbuf(sfd);
         } else {
             error = setsockopt(sfd, SOL_SOCKET, SO_KEEPALIVE, (void *)&flags, sizeof(flags));
@@ -4528,7 +4528,7 @@
             }
         }
 
-        if (IS_UDP(transport)) {
+        if IS_UDP(transport) {
             int c;
 
             for (c = 0; c < settings.num_threads_per_udp; c++) {
