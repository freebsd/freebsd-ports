--- play.c.orig	Sun Jan 22 00:40:17 2006
+++ play.c	Wed May 10 17:31:34 2006
@@ -54,7 +54,6 @@
   int rtn;			/* For return values of pthread fctns. */
   /* Maximum priority of FIFO thread.  Should always be initialized
      elsewhere before use.  */
-  int fifo_max_prio = 0;
   void *au_th_ret;		/* Audio thread return pointer. */
   void *fd_th_ret;		/* File thread return pointer. */
   sigset_t all_sigs;		/* Full set of all signals.  */
@@ -263,6 +262,10 @@
 					  PTHREAD_CREATE_JOINABLE)) ) {
     err_die("BUG: pthread_attr_setdetachstate failed: %s\n", strerror(rtn));
   }
+
+/* This is ugly, but FreeBSD defines _POSIX_THREAD_PRIORITY_SCHEDULING
+   but it does not support PTHREAD_SCOPE_SYSTEM
+ 
 #if defined (_POSIX_THREAD_PRIORITY_SCHEDULING) \
     && _POSIX_THREAD_PRIORITY_SCHEDULING != -1 \
     && _POSIX_THREAD_PRIORITY_SCHEDULING != 0
@@ -282,6 +285,8 @@
       err_die("BUG: pthread_attr_setscope failed: %s\n", strerror(rtn));
   }
 #endif
+*/
+    
   if ( (rtn = pthread_attr_init(&move_fd_attr)) )
     err_die("BUG: pthread_attr_init failed: %s\n", strerror(rtn));
   if ( (rtn = pthread_attr_setdetachstate(&move_fd_attr, 
@@ -289,6 +294,9 @@
     err_die("BUG: pthread_attr_setdetachstate failed: %s\n", strerror(rtn));
   }
 
+/* This is ugly, but FreeBSD defines _POSIX_THREAD_PRIORITY_SCHEDULING
+   but it does not support PTHREAD_SCOPE_SYSTEM
+ 
 #if defined (_POSIX_THREAD_PRIORITY_SCHEDULING) \
     && _POSIX_THREAD_PRIORITY_SCHEDULING != -1 \
     && _POSIX_THREAD_PRIORITY_SCHEDULING != 0
@@ -306,7 +314,7 @@
       err_die("BUG: pthread_attr_setscope failed: %s\n", strerror(rtn));
   }
 #endif
-
+*/
   /* Getting ugly.  Here we install a handler (which sets a global
      flag which the threads can poll in order to do graceful
      death). */
