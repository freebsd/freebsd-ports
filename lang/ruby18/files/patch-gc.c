--- gc.c.orig	Wed Nov 26 22:42:01 2003
+++ gc.c	Wed Nov 26 22:40:43 2003
@@ -32,8 +32,7 @@
 
 #ifdef __ia64__
 #include <ucontext.h>
-#pragma weak __libc_ia64_register_backing_store_base
-extern unsigned long __libc_ia64_register_backing_store_base;
+#define __libc_ia64_register_backing_store_base (4ULL<<61)
 #endif
 
 void re_free_registers _((struct re_registers*));
