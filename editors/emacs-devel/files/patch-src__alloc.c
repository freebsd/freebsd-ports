Index: src/alloc.c
===================================================================
--- src/alloc.c	(.../branches/gnu/emacs)	(revision 15)
+++ src/alloc.c	(.../trunk/emacs)	(revision 15)
@@ -4542,8 +4542,12 @@
      needed on ia64 too.  See mach_dep.c, where it also says inline
      assembler doesn't work with relevant proprietary compilers.  */
 #ifdef sparc
+#ifdef __sparc64__
+  asm ("flushw");
+#else
   asm ("ta 3");
 #endif
+#endif
 
   /* Save registers that we need to see on the stack.  We need to see
      registers used to hold register variables and registers used to
