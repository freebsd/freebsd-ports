--- src/mm/boehm-gc/pthread_support.c.orig	2012-09-03 12:10:00.000000000 -0400
+++ src/mm/boehm-gc/pthread_support.c	2012-10-04 19:46:21.000000000 -0400
@@ -1080,17 +1080,6 @@
     /* can't have been recycled by pthreads.                            */
     UNLOCK();
     result = REAL_FUNC(pthread_join)(thread, retval);
-# if defined (GC_FREEBSD_THREADS)
-    /* On FreeBSD, the wrapped pthread_join() sometimes returns (what
-       appears to be) a spurious EINTR which caused the test and real code
-       to gratuitously fail.  Having looked at system pthread library source
-       code, I see how this return code may be generated.  In one path of
-       code, pthread_join() just returns the errno setting of the thread
-       being joined.  This does not match the POSIX specification or the
-       local man pages thus I have taken the liberty to catch this one
-       spurious return value properly conditionalized on GC_FREEBSD_THREADS. */
-    if (result == EINTR) result = 0;
-# endif
     if (result == 0) {
         LOCK();
         /* Here the pthread thread id may have been recycled. */
