--- apr-0.9.4/build/apr_hints.m4.orig	Mon Jun  2 11:52:28 2003
+++ apr-0.9.4/build/apr_hints.m4	Sun Nov  9 18:15:30 2003
@@ -130,14 +130,15 @@
 	APR_ADDTO(CPPFLAGS, [-DNETBSD])
 	;;
     *-freebsd*)
-	case $host in
-	    *freebsd[2345]*)
-		APR_ADDTO(CFLAGS, [-funsigned-char])
-		;;
-	esac
-	APR_SETIFNULL(enable_threads, [no])
+	os_version=`sysctl -n kern.osreldate`
+	APR_ADDTO(CFLAGS, [-funsigned-char])
         APR_SETIFNULL(apr_lock_method, [USE_FLOCK_SERIALIZE])
-	APR_ADDTO(CPPFLAGS, [-D_REENTRANT -D_THREAD_SAFE])
+	if test $os_version -lt "500016"; then
+		ac_cv_pthreads_cflags="-D_THREAD_SAFE -D_REENTRANT"
+		LIBS="$LIBS -pthread"
+	else
+		ac_cv_pthreads_lib="c_r"
+	fi
 	;;
     *-next-nextstep*)
 	APR_SETIFNULL(CFLAGS, [-O])
