--- aclocal.m4.orig	2009-10-20 02:01:36.000000000 -0500
+++ aclocal.m4	2010-09-29 14:49:41.000000000 -0500
@@ -7985,3 +7985,3 @@
 # generated from the m4 files accompanying Automake X.Y.
-AC_DEFUN([AM_AUTOMAKE_VERSION], [am__api_version="1.9"])
+AC_DEFUN([AM_AUTOMAKE_VERSION], [am__api_version="%%AUTOMAKE_VERSION%%"])
 
@@ -7992,3 +7992,3 @@
 AC_DEFUN([AM_SET_CURRENT_AUTOMAKE_VERSION],
-	 [AM_AUTOMAKE_VERSION([1.9.6])])
+	 [AM_AUTOMAKE_VERSION([%%AUTOMAKE_APIVER%%])])
 
