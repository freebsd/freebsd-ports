--- deps/hiredis/net.c.orig	2019-11-28 14:32:05.942453000 -0500
+++ deps/hiredis/net.c	2019-11-28 14:39:08.326408000 -0500
@@ -178,14 +178,34 @@
         __redisSetError(c,REDIS_ERR_OTHER,strerror(errno));
         return REDIS_ERR;
     }
-#else
-#if defined(__GLIBC__) && !defined(__FreeBSD_kernel__)
+#elif defined(__GLIBC__)
     if (setsockopt(fd, IPPROTO_TCP, TCP_KEEPIDLE, &val, sizeof(val)) < 0) {
         __redisSetError(c,REDIS_ERR_OTHER,strerror(errno));
         return REDIS_ERR;
     }
 
     val = interval/3;
+    if (val == 0) val = 1;
+    if (setsockopt(fd, IPPROTO_TCP, TCP_KEEPINTVL, &val, sizeof(val)) < 0) {
+        __redisSetError(c,REDIS_ERR_OTHER,strerror(errno));
+        return REDIS_ERR;
+    }
+
+    val = 3;
+    if (setsockopt(fd, IPPROTO_TCP, TCP_KEEPCNT, &val, sizeof(val)) < 0) {
+        __redisSetError(c,REDIS_ERR_OTHER,strerror(errno));
+        return REDIS_ERR;
+    }
+#else
+#if !defined(__sun) && defined(TCP_KEEPIDLE) && defined(TCP_KEEPINTL) && \
+    defined(TCP_KEEPCNT)
+    val = interval;
+    if (setsockopt(fd, IPPROTO_TCP, TCP_KEEPIDLE, &val, sizeof(val)) < 0) {
+        __redisSetError(c,REDIS_ERR_OTHER,strerror(errno));
+        return REDIS_ERR;
+    }
+
+    val = internal/3;
     if (val == 0) val = 1;
     if (setsockopt(fd, IPPROTO_TCP, TCP_KEEPINTVL, &val, sizeof(val)) < 0) {
         __redisSetError(c,REDIS_ERR_OTHER,strerror(errno));
