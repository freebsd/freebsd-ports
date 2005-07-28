--- server.c.orig	Fri Jul 29 01:02:48 2005
+++ server.c	Fri Jul 29 01:02:54 2005
@@ -212,8 +212,8 @@
 
 static void del_client (struct client *cli)
 {
-	cli->socket = -1;
 	struct event *e;
+	cli->socket = -1;
 
 	/* Free the event queue - we can't just use event_queue_free(), because
 	 * it can't free() the event's data. */
