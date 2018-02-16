--- memcached.c.orig	2018-02-13 05:09:37 UTC
+++ memcached.c
@@ -316,7 +316,7 @@ static int add_msghdr(conn *c)
     c->msgbytes = 0;
     c->msgused++;
 
-    if (IS_UDP(c->transport)) {
+    if IS_UDP(c->transport) {
         /* Leave room for the UDP header, which we'll fill in later. */
         return add_iov(c, NULL, UDP_HEADER_SIZE);
     }
@@ -582,7 +582,7 @@ conn *conn_new(const int sfd, enum conn_states init_st
         if (init_state == conn_listening) {
             fprintf(stderr, "<%d server listening (%s)\n", sfd,
                 prot_text(c->protocol));
-        } else if (IS_UDP(transport)) {
+        } else if IS_UDP(transport) {
             fprintf(stderr, "<%d server listening (udp)\n", sfd);
         } else if (c->protocol == negotiating_prot) {
             fprintf(stderr, "<%d new auto-negotiating client connection\n",
@@ -752,7 +752,7 @@ static void conn_cleanup(conn *c) {
         c->sasl_conn = NULL;
     }
 
-    if (IS_UDP(c->transport)) {
+    if IS_UDP(c->transport) {
         conn_set_state(c, conn_read);
     }
 }
@@ -822,7 +822,7 @@ static void conn_close(conn *c) {
 static void conn_shrink(conn *c) {
     assert(c != NULL);
 
-    if (IS_UDP(c->transport))
+    if IS_UDP(c->transport)
         return;
 
     if (c->rsize > READ_BUFFER_HIGHWAT && c->rbytes < DATA_BUFFER_SIZE) {
@@ -5253,7 +5253,7 @@ static enum transmit_result transmit(conn *c) {
         if (settings.verbose > 0)
             perror("Failed to write, and not due to blocking");
 
-        if (IS_UDP(c->transport))
+        if IS_UDP(c->transport)
             conn_set_state(c, conn_read);
         else
             conn_set_state(c, conn_closing);
@@ -5694,7 +5694,7 @@ static void drive_machine(conn *c) {
             break;
 
         case conn_closing:
-            if (IS_UDP(c->transport))
+            if IS_UDP(c->transport)
                 conn_cleanup(c);
             else
                 conn_close(c);
@@ -5858,7 +5858,7 @@ static int server_socket(const char *interface,
 #endif
 
         setsockopt(sfd, SOL_SOCKET, SO_REUSEADDR, (void *)&flags, sizeof(flags));
-        if (IS_UDP(transport)) {
+        if IS_UDP(transport) {
             maximize_sndbuf(sfd);
         } else {
             error = setsockopt(sfd, SOL_SOCKET, SO_KEEPALIVE, (void *)&flags, sizeof(flags));
@@ -5913,7 +5913,7 @@ static int server_socket(const char *interface,
             }
         }
 
-        if (IS_UDP(transport)) {
+        if IS_UDP(transport) {
             int c;
 
             for (c = 0; c < settings.num_threads_per_udp; c++) {
