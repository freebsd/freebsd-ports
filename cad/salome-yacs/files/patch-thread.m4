--- adm/unix/config_files/thread.m4.orig	2009-05-28 22:07:41.000000000 +0700
+++ adm/unix/config_files/thread.m4	2009-07-16 16:59:05.000000000 +0700
@@ -35,6 +35,13 @@
    AC_CHECK_HEADER(pthread.h,thread_ok=yes ,thread_ok=no)
    thread_ok="yes"
 fi
+if test `uname` = "FreeBSD"
+then
+   THREAD_DEF="-DYACS_PTHREAD"
+   AC_CHECK_HEADER(pthread.h,thread_ok=yes ,thread_ok=no)
+   thread_ok="yes"
+fi
+
 
 AC_LANG_RESTORE
 AC_MSG_RESULT(for THREADs: $thread_ok)
@@ -120,6 +127,12 @@
 
         acx_pthread_flags="-pthread -pthreads pthread -mt $acx_pthread_flags"
         ;;
+
+        *freebsd*)
+        acx_pthread_flags="-pthread -pthreads -kthread"
+
+        ;;
+        
 esac
 
 if test x"$acx_pthread_ok" = xno; then
