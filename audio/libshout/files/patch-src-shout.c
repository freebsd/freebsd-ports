Obtained from:	https://gitlab.xiph.org/xiph/icecast-libshout/commit/0ac7ed9e84c3871d4427acc1ce59dca5e4af21ef

--- src/shout.c.orig	2019-05-22 09:05:32 UTC
+++ src/shout.c
@@ -417,7 +417,7 @@ int shout_set_metadata(shout_t *self, sh
 #ifdef HAVE_OPENSSL
     shout_connection_select_tlsmode(connection, self->tls_mode);
 #endif
-    shout_connection_set_nonblocking(connection, 0);
+    shout_connection_set_nonblocking(connection, SHOUT_BLOCKING_FULL);
 
     connection->target_message_state = SHOUT_MSGSTATE_PARSED_FINAL;
 
@@ -989,7 +989,10 @@ unsigned int shout_get_protocol(shout_t 
 
 int shout_set_nonblocking(shout_t *self, unsigned int nonblocking)
 {
-    if (!self || (nonblocking != 0 && nonblocking != 1))
+    if (nonblocking == SHOUT_BLOCKING_DEFAULT)
+        nonblocking = SHOUT_BLOCKING_FULL;
+
+    if (!self || (nonblocking != SHOUT_BLOCKING_FULL && nonblocking != SHOUT_BLOCKING_NONE))
         return SHOUTERR_INSANE;
 
     if (self->connection)
