--- eval.c.orig	Wed Nov 26 22:41:47 2003
+++ eval.c	Wed Nov 26 22:40:38 2003
@@ -7788,8 +7788,7 @@
 
 #ifdef __ia64__
 #include <ucontext.h>
-#pragma weak __libc_ia64_register_backing_store_base
-extern unsigned long __libc_ia64_register_backing_store_base;
+#define __libc_ia64_register_backing_store_base (4ULL<<61)
 #endif
 
 /* Windows SEH refers data on the stack. */
