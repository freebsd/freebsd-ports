--- apr-0.9.4/build/apr_hints.m4.orig	Mon Dec 22 18:26:10 2003
+++ apr-0.9.4/build/apr_hints.m4	Fri Jan 30 22:53:49 2004
@@ -129,14 +129,19 @@
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
+		ac_cv_pthreads_lib="-pthread"
+	elif test $os_version -lt "502102"; then
+		ac_cv_pthreads_cflags="none"
+		ac_cv_pthreads_lib="c_r"
+	else
+		ac_cv_pthreads_cflags="none"
+		ac_cv_pthreads_lib="pthread"
+	fi
 	;;
     *-next-nextstep*)
 	APR_SETIFNULL(CFLAGS, [-O])
