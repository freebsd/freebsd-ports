--- inc/sync_unix.h.orig	2009-11-20 20:53:02.000000000 +0800
+++ inc/sync_unix.h	2010-08-16 13:56:02.000000000 +0800
@@ -160,7 +160,7 @@
     }
 
     static int getCurrentThreadId() {
-        return (int)pthread_self();
+        return reinterpret_cast<unsigned long>(pthread_self());
     }
 
     static int numberOfProcessors();
