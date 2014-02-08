--- libsoup/soup-message-io.c.orig	2014-02-03 23:20:23.000000000 +0100
+++ libsoup/soup-message-io.c	2014-02-03 23:23:10.000000000 +0100
@@ -977,7 +977,7 @@ soup_message_io_run_until_finish (SoupMe
 	g_object_ref (msg);
 
 	if (io) {
-		g_return_if_fail (io->mode == SOUP_MESSAGE_IO_CLIENT);
+		g_return_val_if_fail (io->mode == SOUP_MESSAGE_IO_CLIENT, FALSE);
 
 		if (io->read_state < SOUP_MESSAGE_IO_STATE_BODY_DONE)
 			io->read_state = SOUP_MESSAGE_IO_STATE_FINISHING;
