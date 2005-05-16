--- threadpool.c.orig	Tue Dec 14 13:56:23 2004
+++ threadpool.c	Mon May 16 19:23:22 2005
@@ -279,9 +279,9 @@
 void CP_ThreadPool_QueueWorkItem(CP_SThreadPool *pTPThis, CP_TPfnJob pfnCallback,
                                  void *arg1, void *arg2)
 {
-    ts_mutex_lock(pTPThis->mtJobQueueMutex);
-
     CP_STPJobQueue *pTPJQNewJob = malloc(sizeof(CP_STPJobQueue));
+
+    ts_mutex_lock(pTPThis->mtJobQueueMutex);
 
     pTPJQNewJob->fnJobCallback = pfnCallback;
     pTPJQNewJob->arg1 = arg1;
