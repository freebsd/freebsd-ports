--- TSRM/threads.m4.orig	Fri May  5 08:02:38 2006
+++ TSRM/threads.m4	Fri May  5 08:02:59 2006
@@ -164,7 +164,7 @@ dnl
 dnl
 AC_DEFUN([PTHREADS_ASSIGN_VARS],[
 if test -n "$ac_cv_pthreads_lib"; then
-  LIBS="$LIBS -l$ac_cv_pthreads_lib"
+  LIBS="$LIBS $ac_cv_pthreads_lib"
 fi
 
 if test -n "$ac_cv_pthreads_cflags"; then
