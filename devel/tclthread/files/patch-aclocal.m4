--- aclocal.m4.orig	2016-04-08 09:07:17 UTC
+++ aclocal.m4
@@ -22,7 +22,7 @@ AC_DEFUN(TCLTHREAD_WITH_GDBM, [
 	[  --with-gdbm             link with optional GDBM support],\
 	with_gdbm=${withval})
 
-    if test x"${with_gdbm}" != x; then
+    if test x"${with_gdbm}" != "x" -a "${with_gdbm}" != "no"; then
 
     AC_MSG_CHECKING([for GNU gdbm library])
 
