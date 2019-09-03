Obtained from:	https://gitlab.xiph.org/xiph/icecast-libshout/commit/0ac7ed9e84c3871d4427acc1ce59dca5e4af21ef
		https://gitlab.xiph.org/xiph/icecast-libshout/commit/b807c1e2550718bdc73d65ac1b05255d18f45c54

--- src/connection.c.orig	2019-05-20 19:32:59 UTC
+++ src/connection.c
@@ -118,7 +118,7 @@ static struct timeval shout_connection_i
             .tv_usec = (timeout % 1000) * 1000
         };
         return tv;
-    } else if (con->nonblocking) {
+    } else if (con->nonblocking == SHOUT_BLOCKING_NONE) {
         return tv_nonblocking;
     } else {
         return tv_blocking;
@@ -167,7 +167,7 @@ static shout_connection_return_state_t s
             }
         break;
         case SHOUT_SOCKSTATE_CONNECTING:
-            if (con->nonblocking) {
+            if (con->nonblocking == SHOUT_BLOCKING_NONE) {
                 ret = shout_connection_iter__wait_for_io(con, shout, 1, 1, 0);
                 if (ret != SHOUT_RS_DONE) {
                     return ret;
@@ -460,7 +460,7 @@ int                 shout_connection_ite
             break; \
             case SHOUT_RS_TIMEOUT: \
             case SHOUT_RS_NOTNOW: \
-                if (con->nonblocking) \
+                if (con->nonblocking == SHOUT_BLOCKING_NONE) \
                     return SHOUTERR_RETRY; \
                 retry = 1; \
             break; \
@@ -518,7 +518,7 @@ int                 shout_connection_sel
 }
 int                 shout_connection_set_nonblocking(shout_connection_t *con, unsigned int nonblocking)
 {
-    if (!con)
+    if (!con || (nonblocking != SHOUT_BLOCKING_DEFAULT && nonblocking != SHOUT_BLOCKING_FULL && nonblocking != SHOUT_BLOCKING_NONE))
         return SHOUTERR_INSANE;
 
     if (con->socket != SOCK_ERROR)
@@ -563,13 +563,14 @@ int                 shout_connection_con
     if (con->socket != SOCK_ERROR || con->current_socket_state != SHOUT_SOCKSTATE_UNCONNECTED)
         return SHOUTERR_BUSY;
 
-    shout_connection_set_nonblocking(con, shout_get_nonblocking(shout));
+    if (con->nonblocking == SHOUT_BLOCKING_DEFAULT)
+        shout_connection_set_nonblocking(con, shout_get_nonblocking(shout));
 
     port = shout->port;
-    if (shout_get_protocol(shout) == SHOUT_PROTOCOL_ICY)
+    if (con->impl == shout_icy_impl)
         port++;
 
-    if (con->nonblocking) {
+    if (con->nonblocking == SHOUT_BLOCKING_NONE) {
         con->socket = sock_connect_non_blocking(shout->host, port);
     } else {
         con->socket = sock_connect(shout->host, port);
