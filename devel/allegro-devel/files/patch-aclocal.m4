--- aclocal.m4.orig	2007-06-16 01:52:28.000000000 +0000
+++ aclocal.m4	2008-07-14 15:10:32.000000000 +0000
@@ -195,3 +195,2 @@
 dnl
-AC_MSG_CHECKING(for System V sys/procfs)
 AC_DEFUN(ALLEGRO_ACTEST_SV_PROCFS, [
@@ -211,3 +210,2 @@
 ])
-AC_MSG_RESULT($allegro_sv_procfs)
 
@@ -219,3 +217,2 @@
 dnl
-AC_MSG_CHECKING(if sys/procfs.h tells us argc/argv)
 AC_DEFUN(ALLEGRO_ACTEST_PROCFS_ARGCV, [
@@ -228,3 +225,2 @@
 ])
-AC_MSG_RESULT($allegro_procfs_argcv)
 
@@ -236,3 +232,2 @@
 dnl
-AC_MSG_CHECKING(for getexecname)
 AC_DEFUN(ALLEGRO_ACTEST_SYS_GETEXECNAME,
@@ -242,3 +237,2 @@
 )
-AC_MSG_RESULT($allegro_sys_getexecname)
 
