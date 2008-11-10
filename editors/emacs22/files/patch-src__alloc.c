--- src/alloc.c.orig	2008-09-07 05:25:27.000000000 +0300
+++ src/alloc.c	2008-09-07 05:25:27.000000000 +0300
@@ -4573,8 +4573,12 @@
      needed on ia64 too.  See mach_dep.c, where it also says inline
      assembler doesn't work with relevant proprietary compilers.  */
 #ifdef __sparc__
+#ifdef __sparc64__
+  asm ("flushw");
+#else
   asm ("ta 3");
 #endif
+#endif
 
   /* Save registers that we need to see on the stack.  We need to see
      registers used to hold register variables and registers used to
