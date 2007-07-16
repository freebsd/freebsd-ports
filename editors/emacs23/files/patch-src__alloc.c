--- ./src/alloc.c.orig	Thu Aug 31 20:50:29 2006
+++ ./src/alloc.c	Fri Sep  1 21:10:08 2006
@@ -4560,7 +4560,11 @@
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
