--- TSRM/threads.m4.orig	Wed Apr 27 15:22:18 2005
+++ TSRM/threads.m4	Wed May  3 10:02:34 2006
@@ -164,7 +164,7 @@
 dnl
 AC_DEFUN([PTHREADS_ASSIGN_VARS],[
 if test -n "$ac_cv_pthreads_lib"; then
-  LIBS="$LIBS -l$ac_cv_pthreads_lib"
+  LIBS="$LIBS $ac_cv_pthreads_lib"
 fi
 
 if test -n "$ac_cv_pthreads_cflags"; then
