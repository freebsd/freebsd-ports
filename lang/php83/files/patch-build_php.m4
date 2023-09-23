--- build/php.m4.orig	2023-09-23 00:45:39 UTC
+++ build/php.m4
@@ -2713,7 +2713,7 @@ AC_DEFUN([PHP_CHECK_BUILTIN_CPU_INIT], [
   AC_MSG_CHECKING([for __builtin_cpu_init])
 
   AC_LINK_IFELSE([AC_LANG_PROGRAM([], [[
-    return __builtin_cpu_init()? 1 : 0;
+    __builtin_cpu_init();
   ]])], [
     have_builtin_cpu_init=1
     AC_MSG_RESULT([yes])
