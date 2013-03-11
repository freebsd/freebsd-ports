--- app/base/base-utils.c~
+++ app/base/base-utils.c
@@ -29,7 +29,7 @@
 #include <process.h>
 #endif
 
-#ifdef G_OS_UNIX
+#ifdef __GLIBC__
 /* For get_backtrace() */
 #include <stdlib.h>
 #include <string.h>
@@ -112,7 +112,7 @@ get_physical_memory_size (void)
 char *
 get_backtrace (void)
 {
-#ifdef G_OS_UNIX
+#ifdef __GLIBC__
   void     *functions[MAX_FUNC];
   char    **function_names;
   int       n_functions;
