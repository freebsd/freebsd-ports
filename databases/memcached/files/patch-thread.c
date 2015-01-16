--- thread.c.orig	2015-01-16 16:22:19.000000000 +0000
+++ thread.c	2015-01-16 16:22:27.000000000 +0000
@@ -409,7 +409,7 @@
         conn *c = conn_new(item->sfd, item->init_state, item->event_flags,
                            item->read_buffer_size, item->transport, me->base);
         if (c == NULL) {
-            if (IS_UDP(item->transport)) {
+            if IS_UDP(item->transport) {
                 fprintf(stderr, "Can't listen for events on UDP socket\n");
                 exit(1);
             } else {
