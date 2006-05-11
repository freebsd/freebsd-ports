--- record.c.orig	Sun Jan 22 00:40:17 2006
+++ record.c	Wed May 10 17:31:45 2006
@@ -43,7 +43,6 @@
   int rtn;		  /* For return values of pthread fctns. */
   /* Maximum priority of FIFO thread.  Should always be rinitialized
      elsewhere before use.  */
-  int fifo_max_prio = 0;	  
   void *au_th_ret;   	  /* Audio thread return pointer. */
   void *fd_th_ret;	  /* File thread return pointer. */
   sigset_t all_sigs;      /* Full set of all signals.  */
@@ -183,6 +182,10 @@
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
@@ -202,12 +205,17 @@
       err_die("BUG: pthread_attr_setscope failed: %s\n", strerror(rtn));
   }
 #endif
+*/    
   if ( (rtn = pthread_attr_init(&move_fd_attr)) )
     err_die("BUG: pthread_attr_init failed: %s\n", strerror(rtn));
   if ( (rtn = pthread_attr_setdetachstate(&move_fd_attr, 
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
@@ -225,6 +233,7 @@
       err_die("BUG: pthread_attr_setscope failed: %s\n", strerror(rtn));
   }
 #endif
+*/
 
   /* Getting ugly.  Here we install a handler (which sets a global
      flag which the threads can poll in order to do graceful
