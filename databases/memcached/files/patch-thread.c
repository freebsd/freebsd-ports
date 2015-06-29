--- thread.c.orig	2015-04-20 05:34:19 UTC
+++ thread.c
@@ -402,7 +402,7 @@ static void thread_libevent_process(int 
         conn *c = conn_new(item->sfd, item->init_state, item->event_flags,
                            item->read_buffer_size, item->transport, me->base);
         if (c == NULL) {
-            if (IS_UDP(item->transport)) {
+            if IS_UDP(item->transport) {
                 fprintf(stderr, "Can't listen for events on UDP socket\n");
                 exit(1);
             } else {
