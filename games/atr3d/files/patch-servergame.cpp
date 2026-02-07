--- servergame.cpp.orig	2008-02-19 18:59:58.000000000 +0100
+++ servergame.cpp	2008-02-19 19:03:29.000000000 +0100
@@ -66,7 +66,7 @@
 
   ServerGameRunning=1;
 
-  threadnum=(int)threadid;
+  threadnum=(size_t)threadid;
 
   pthread_mutex_lock(&ServerLock);
 
