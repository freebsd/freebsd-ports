--- jslock.c	2007-03-29 23:55:35.000000000 +0200
+++ jslock.c	2008-06-19 16:08:19.000000000 +0200
@@ -224,7 +224,9 @@
 #endif
 }
 
+#ifndef NSPR_LOCK
 static void js_Dequeue(JSThinLock *);
+#endif
 
 #ifdef DEBUG_SCOPE_COUNT
 
