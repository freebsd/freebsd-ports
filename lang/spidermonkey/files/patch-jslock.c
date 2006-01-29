--- jslock.c.orig	Sat Jan 14 02:20:18 2006
+++ jslock.c	Sat Jan 14 02:22:17 2006
@@ -193,7 +193,9 @@
 #endif
 }
 
+#ifndef NSPR_LOCK
 static void js_Dequeue(JSThinLock *);
+#endif
 
 #ifdef DEBUG_SCOPE_COUNT
