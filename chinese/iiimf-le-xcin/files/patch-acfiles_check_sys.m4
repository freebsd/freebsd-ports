--- acfiles/check_sys.m4.orig	Wed Dec 10 12:42:54 2003
+++ acfiles/check_sys.m4	Fri Sep 10 00:33:55 2004
@@ -73,6 +73,11 @@
 ## Checks for thread library.
 	AC_CHECK_LIB(pthread, pthread_create, [ HAVE_LIBPTHREAD="yes" ])
 	AC_CHECK_LIB(thread, thr_create, [ HAVE_LIBUITHREAD="yes" ])
+
+	case "${target}" in
+		*freebsd*) HAVE_LIBPTHREAD="yes";;
+	esac
+
 	if test "X${HAVE_LIBPTHREAD}" = "Xyes" ; then
 		HAVE_THREAD="pthread"
 	elif test "X${HAVE_LIBUITHREAD}" = "Xyes" ; then
@@ -194,8 +199,6 @@
 		COMMON_CXX_CFLAGS="${COMMON_CXX_CFLAGS} -DLinux"
 		;;
 	    *freebsd*)
-		THREAD_LDFLAGS="-pthread"
-		PTHREAD_LIBS=""
 		;;
 	esac
 
@@ -245,9 +248,9 @@
 	    *solaris*@cc:*)
 		THREAD_CXX_CFLAGS="-mt"
 		;;
-	    *freebsd*@gcc:*)
-		THREAD_LDFLAGS="-pthread"
-		THREAD_LIBS=""
+ 	    *freebsd*)
+ 		THREAD_CXX_CFLAGS="${PTHREAD_CFLAGS}"
+ 		THREAD_LIBS="${PTHREAD_LIBS}"
 		;;
 	    *linux*)
 		THREAD_CXX_CFLAGS="${THREAD_CXX_CFLAGS} -D_SVID_SOURCE -D_BSD_SOURCE"
