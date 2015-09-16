--- hiredis.c.orig	2015-08-25 12:16:20 UTC
+++ hiredis.c
@@ -808,7 +808,6 @@ int redisBufferRead(redisContext *c) {
             return REDIS_ERR;
         }
     } else if (nread == 0) {
-        c->flags &= ~REDIS_CONNECTED;
         __redisSetError(c,REDIS_ERR_EOF,"Server closed the connection");
         return REDIS_ERR;
     } else {
