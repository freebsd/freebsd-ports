--- acinclude.m4.orig	2004-02-07 17:15:46 UTC
+++ acinclude.m4
@@ -284,8 +284,6 @@ AC_DEFUN([LSH_GCC_ATTRIBUTES],
 	       lsh_cv_c_attribute,
 [ AC_TRY_COMPILE([
 #include <stdlib.h>
-],
-[
 static void foo(void) __attribute__ ((noreturn));
 
 static void __attribute__ ((noreturn))
@@ -293,6 +291,8 @@ foo(void)
 {
   exit(1);
 }
+],
+[
 ],
 lsh_cv_c_attribute=yes,
 lsh_cv_c_attribute=no)])
