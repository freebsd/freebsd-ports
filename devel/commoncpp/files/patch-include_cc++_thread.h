--- include/cc++/thread.h.orig	Sat Jan 17 17:51:01 2004
+++ include/cc++/thread.h	Thu Dec 23 16:38:55 2004
@@ -914,7 +914,7 @@
 	static Thread* _main;
 
 	Thread *_parent;
-	enum Cancel _cancel;
+	Cancel _cancel;
 	Semaphore *_start;
 
 	// private data
