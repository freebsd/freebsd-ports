--- apr-1.3.6/build/apr_hints.m4.orig	Wed Oct 27 11:12:28 2004
+++ apr-1.3.6/build/apr_hints.m4	Wed Oct 27 11:25:32 2004
@@ -137,11 +137,7 @@
 	;;
     *-freebsd*)
         APR_SETIFNULL(apr_lock_method, [USE_FLOCK_SERIALIZE])
-        if test -x /sbin/sysctl; then
-            os_version=`/sbin/sysctl -n kern.osreldate`
-        else
-            os_version=000000
-        fi
+        os_version="OSVERSION"
         # 502102 is when libc_r switched to libpthread (aka libkse).
         if test $os_version -ge "502102"; then
           apr_cv_pthreads_cflags="none"
