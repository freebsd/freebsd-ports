--- build/apr_hints.m4.orig	2015-04-05 07:04:48 UTC
+++ build/apr_hints.m4
@@ -147,15 +147,11 @@ dnl	       # Not a problem in 10.20.  Ot
 	;;
     *-freebsd*)
         APR_SETIFNULL(apr_lock_method, [USE_FLOCK_SERIALIZE])
-        if test -x /sbin/sysctl; then
-            os_version=`/sbin/sysctl -n kern.osreldate`
-        else
-            os_version=000000
-        fi
+        osversion=%%OSVERSION%%
         # 502102 is when libc_r switched to libpthread (aka libkse).
         if test $os_version -ge "502102"; then
           apr_cv_pthreads_cflags="none"
-          apr_cv_pthreads_lib="-lpthread"
+          apr_cv_pthreads_lib="-pthread"
         else
           APR_ADDTO(CPPFLAGS, [-D_THREAD_SAFE -D_REENTRANT])
           APR_SETIFNULL(enable_threads, [no])
