--- src/alloc.c.orig	Tue Jul 04 16:55:30 2006 +0300
+++ src/alloc.c	Tue Jul 04 16:58:01 2006 +0300
@@ -4542,7 +4542,11 @@ mark_stack ()
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
