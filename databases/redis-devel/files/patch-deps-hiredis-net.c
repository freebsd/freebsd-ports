--- deps/hiredis/net.c.orig	2014-09-12 09:16:58.000000000 -0500
+++ deps/hiredis/net.c	2014-09-16 19:45:20.339820576 -0500
@@ -138,7 +138,8 @@ int redisKeepAlive(redisContext *c, int 
         return REDIS_ERR;
     }
 #else
-#ifndef __sun
+#if !defined(__sun) && defined(TCP_KEEPIDLE) && defined(TCP_KEEPINTVL) && \
+    defined(TCP_KEEPCNT)
     val = interval;
     if (setsockopt(fd, IPPROTO_TCP, TCP_KEEPIDLE, &val, sizeof(val)) < 0) {
         __redisSetError(c,REDIS_ERR_OTHER,strerror(errno));
