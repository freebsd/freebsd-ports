--- src/alloc.c.orig	2008-08-12 20:35:44.000000000 +0200
+++ src/alloc.c	2013-09-07 21:52:46.000000000 +0200
@@ -1205,6 +1205,9 @@
 #endif /* GC_MALLOC_CHECK */
 
   __free_hook = old_free_hook;
+#ifdef __GNUC__
+  __asm __volatile ("" : : : "memory");
+#endif
   free (ptr);
 
   /* If we released our reserve (due to running out of memory),
@@ -1236,6 +1239,9 @@
 
   BLOCK_INPUT_ALLOC;
   __malloc_hook = old_malloc_hook;
+#ifdef __GNUC__
+  __asm __volatile ("" : : : "memory");
+#endif
 #ifdef DOUG_LEA_MALLOC
     mallopt (M_TOP_PAD, malloc_hysteresis * 4096);
 #else
@@ -1285,6 +1291,9 @@
 
   BLOCK_INPUT_ALLOC;
   __realloc_hook = old_realloc_hook;
+#ifdef __GNUC__
+  __asm __volatile ("" : : : "memory");
+#endif
 
 #ifdef GC_MALLOC_CHECK
   if (ptr)
@@ -4573,8 +4582,12 @@
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
