--- libdrizzle/handshake.c.orig	2009-11-05 22:46:41 UTC
+++ libdrizzle/handshake.c
@@ -121,7 +121,7 @@ drizzle_return_t drizzle_state_handshake_server_read(d
     return DRIZZLE_RETURN_BAD_HANDSHAKE_PACKET;
   }
 
-  if (con->packet_size != (46 + (size_t)(ptr - con->buffer_ptr)))
+  if (con->packet_size < (46 + (size_t)(ptr - con->buffer_ptr)))
   {
     drizzle_set_error(con->drizzle, "drizzle_state_handshake_server_read",
                       "bad packet size:%zu:%zu",
