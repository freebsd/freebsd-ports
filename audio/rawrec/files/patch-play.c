--- play.c.orig	Fri Nov 29 03:33:21 2002
+++ play.c	Thu Sep  4 22:13:08 2003
@@ -263,6 +263,10 @@
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
@@ -282,6 +286,8 @@
       err_die("BUG: pthread_attr_setscope failed: %s\n", strerror(rtn));
   }
 #endif
+*/
+    
   if ( (rtn = pthread_attr_init(&move_fd_attr)) )
     err_die("BUG: pthread_attr_init failed: %s\n", strerror(rtn));
   if ( (rtn = pthread_attr_setdetachstate(&move_fd_attr, 
@@ -289,6 +295,9 @@
     err_die("BUG: pthread_attr_setdetachstate failed: %s\n", strerror(rtn));
   }
 
+/* This is ugly, but FreeBSD defines _POSIX_THREAD_PRIORITY_SCHEDULING
+   but it does not support PTHREAD_SCOPE_SYSTEM
+ 
 #if defined (_POSIX_THREAD_PRIORITY_SCHEDULING) \
     && _POSIX_THREAD_PRIORITY_SCHEDULING != -1 \
     && _POSIX_THREAD_PRIORITY_SCHEDULING != 0
@@ -306,7 +315,7 @@
       err_die("BUG: pthread_attr_setscope failed: %s\n", strerror(rtn));
   }
 #endif
-
+*/
   /* Getting ugly.  Here we install a handler (which sets a global
      flag which the threads can poll in order to do graceful
      death). */
