--- ./build/apr_hints.m4.orig	2010-02-06 16:14:03.000000000 -0500
+++ ./build/apr_hints.m4	2010-05-26 23:19:19.263812317 -0400
@@ -159,15 +159,11 @@
 	;;
     *-freebsd*)
         APR_SETIFNULL(apr_lock_method, [USE_FLOCK_SERIALIZE])
-        if test -x /sbin/sysctl; then
-            os_version=`/sbin/sysctl -n kern.osreldate`
-        else
-            os_version=000000
-        fi
+        osversion="${900010}"
         # 502102 is when libc_r switched to libpthread (aka libkse).
         if test $os_version -ge "502102"; then
           apr_cv_pthreads_cflags="none"
-          apr_cv_pthreads_lib="-lpthread"
+          apr_cv_pthreads_lib="-pthread"
         else
           APR_ADDTO(CPPFLAGS, [-D_THREAD_SAFE -D_REENTRANT])
           APR_SETIFNULL(enable_threads, [no])
