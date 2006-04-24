--- ./compat/Thread.c.orig	Mon Apr 24 11:02:47 2006
+++ ./compat/Thread.c	Mon Apr 24 11:03:46 2006
@@ -202,7 +202,7 @@
 #if   defined( HAVE_POSIX_THREAD )
             // Cray J90 doesn't have pthread_cancel; Iperf works okay without
 #ifdef HAVE_PTHREAD_CANCEL
-            pthread_cancel( oldTID );
+            pthread_cancel( thread->mTID );
 #endif
 #else // Win32
             // this is a somewhat dangerous function; it's not
