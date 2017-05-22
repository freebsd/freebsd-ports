--- deps/hiredis/net.c.orig	2017-04-22 07:23:27.000000000 -0400
+++ deps/hiredis/net.c	2017-05-05 20:02:09.292479000 -0400
@@ -135,13 +135,12 @@
 
     val = interval;
 
-#ifdef _OSX
+#if defined(_OSX)
     if (setsockopt(fd, IPPROTO_TCP, TCP_KEEPALIVE, &val, sizeof(val)) < 0) {
         __redisSetError(c,REDIS_ERR_OTHER,strerror(errno));
         return REDIS_ERR;
     }
-#else
-#if defined(__GLIBC__) && !defined(__FreeBSD_kernel__)
+#elif defined(__GLIBC__)
     val = interval;
     if (setsockopt(fd, IPPROTO_TCP, TCP_KEEPIDLE, &val, sizeof(val)) < 0) {
         __redisSetError(c,REDIS_ERR_OTHER,strerror(errno));
@@ -160,6 +159,27 @@
         __redisSetError(c,REDIS_ERR_OTHER,strerror(errno));
         return REDIS_ERR;
     }
+#else
+#if !defined(__sun) && defined(TCP_KEEPIDLE) && defined(TCP_KEEPINTVL) && \
+    defined(TCP_KEEPCNT)
+    val = interval;
+    if (setsockopt(fd, IPPROTO_TCP, TCP_KEEPIDLE, &val, sizeof(val)) < 0) {
+        __redisSetError(c,REDIS_ERR_OTHER,strerror(errno));
+        return REDIS_ERR;
+    }
+ 
+    val = interval/3;
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
 #endif
 #endif
 
@@ -431,7 +451,7 @@
     struct sockaddr_un sa;
     long timeout_msec = -1;
 
-    if (redisCreateSocket(c,AF_LOCAL) < 0)
+    if (redisCreateSocket(c,AF_UNIX) < 0)
         return REDIS_ERR;
     if (redisSetBlocking(c,0) != REDIS_OK)
         return REDIS_ERR;
@@ -456,7 +476,7 @@
     if (redisContextTimeoutMsec(c,&timeout_msec) != REDIS_OK)
         return REDIS_ERR;
 
-    sa.sun_family = AF_LOCAL;
+    sa.sun_family = AF_UNIX;
     strncpy(sa.sun_path,path,sizeof(sa.sun_path)-1);
     if (connect(c->fd, (struct sockaddr*)&sa, sizeof(sa)) == -1) {
         if (errno == EINPROGRESS && !blocking) {
