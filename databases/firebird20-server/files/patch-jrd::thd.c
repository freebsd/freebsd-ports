--- jrd/thd.c.orig	Thu May 24 14:11:11 2001
+++ jrd/thd.c	Sun Jul  7 14:52:07 2002
@@ -2605,7 +2605,7 @@
 int 		detach_state=PTHREAD_CREATE_DETACHED
 #endif
 
-#if ( !defined HP10 && !defined linux )
+#if ( !defined HP10 && !defined linux && !defined FREEBSD )
 
 state = pthread_attr_init (&pattr);
 if (state)
@@ -2628,7 +2628,7 @@
 return state;
 
 #else
-#ifdef linux
+#if ( defined linux || defined FREEBSD )
 if (state = pthread_create (&thread, NULL, routine, arg))
     return state;
 return pthread_detach (thread);
