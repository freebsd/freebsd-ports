--- src/hawknl/src/htmutex.c.orig	2010-04-14 20:48:09.000000000 +0200
+++ src/hawknl/src/htmutex.c	2010-04-14 20:48:09.000000000 +0200
@@ -72,7 +72,7 @@
             return ENOMEM;
 	    }
         (void)pthread_mutexattr_init(&attr);
-#if defined MACOSX
+#if defined MACOSX || defined __FreeBSD__
         /* GUSI is not fully POSIX compliant, and does not
          * define PTHREAD_MUTEX_ERRORCHECK
          * http://lists.apple.com/archives/unix-porting/2005/May/msg00021.html
