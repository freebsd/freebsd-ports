--- files/patch-utils.h.orig	2018-10-23 00:26:19 UTC
+++ files/patch-utils.h
@@ -0,0 +1,20 @@
+--- utils.h.orig	2018-09-19 23:05:31 UTC
++++ utils.h
+@@ -121,7 +121,7 @@ int clock_gettime(int type, struct timespec *tv);
+  * This returns a constant expression while determining if an argument is
+  * a constant expression, most importantly without evaluating the argument.
+  */
+-#define __is_constant(x)						\
++#define __is_it_constant(x)						\
+ 	(sizeof(int) == sizeof(*(1 ? ((void*)((long)(x) * 0l)) : (int*)1)))
+ 
+ #define __eval_once(func, x)						\
+@@ -136,7 +136,7 @@ int clock_gettime(int type, struct timespec *tv);
+ #define __eval_safe(func, x) __eval_once(func, x)
+ #else
+ #define __eval_safe(func, x)						\
+-	__builtin_choose_expr(__is_constant(x),				\
++	__builtin_choose_expr(__is_it_constant(x),			\
+ 			      func(x), __eval_once(func, x))
+ #endif
+ 
