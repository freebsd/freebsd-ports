--- eval.c.orig	Sun Dec 12 18:26:23 2004
+++ eval.c	Sun Dec 12 18:26:53 2004
@@ -2051,7 +2051,7 @@
 #ifdef GCC_SPARC_BUG
   SCM arg1;
 #else
-  struct {SCM arg_1;} t;
+  volatile struct {SCM arg_1;} t;
 # define arg1 t.arg_1
 #endif
   SCM arg2, arg3, proc;
