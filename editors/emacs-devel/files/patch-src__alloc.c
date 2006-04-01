--- src/alloc.c.orig	Sat Apr  1 23:41:43 2006
+++ src/alloc.c	Sat Apr  1 23:42:32 2006
@@ -4528,7 +4528,11 @@
      needed on ia64 too.  See mach_dep.c, where it also says inline
      assembler doesn't work with relevant proprietary compilers.  */
 #ifdef sparc
+#ifdef __sparc64__
+  asm ("flushw");
+#else
   asm ("ta 3");
+#endif
 #endif
 
   /* Save registers that we need to see on the stack.  We need to see
