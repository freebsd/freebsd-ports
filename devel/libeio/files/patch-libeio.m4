--- libeio.m4.orig	2013-05-28 09:30:57.000000000 +0400
+++ libeio.m4	2013-05-28 09:31:05.000000000 +0400
@@ -2,13 +2,6 @@
 dnl but that header isn't very portable...
 AC_CHECK_HEADERS([stdint.h sys/syscall.h sys/prctl.h])
 
-AC_SEARCH_LIBS(
-   pthread_create,
-   [pthread pthreads pthreadVC2],
-   ,
-   [AC_MSG_ERROR(pthread functions not found)]
-)
-
 AC_CACHE_CHECK(for utimes, ac_cv_utimes, [AC_LINK_IFELSE([[
 #include <sys/types.h>
 #include <sys/time.h>
