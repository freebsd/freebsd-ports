--- src/alloc.c.orig	Thu Sep 12 13:50:01 2002
+++ src/alloc.c	Thu Sep 12 13:48:11 2002
@@ -685,6 +685,9 @@
 #endif /* GC_MALLOC_CHECK */
   
   __free_hook = old_free_hook;
+#ifdef __GNUC__
+  __asm __volatile ("" : : : "memory");
+#endif
   free (ptr);
   
   /* If we released our reserve (due to running out of memory),
@@ -728,6 +731,9 @@
 
   BLOCK_INPUT;
   __malloc_hook = old_malloc_hook;
+#ifdef __GNUC__
+  __asm __volatile ("" : : : "memory");
+#endif
 #ifdef DOUG_LEA_MALLOC
     mallopt (M_TOP_PAD, malloc_hysteresis * 4096);
 #else
@@ -776,6 +782,9 @@
 
   BLOCK_INPUT;
   __realloc_hook = old_realloc_hook;
+#ifdef __GNUC__
+  __asm __volatile ("" : : : "memory");
+#endif
 
 #ifdef GC_MALLOC_CHECK
   if (ptr)
@@ -3723,8 +3732,12 @@
   /* This trick flushes the register windows so that all the state of
      the process is contained in the stack.  */
 #ifdef sparc
+#ifdef __sparc64__
+  asm ("flushw");
+#else
   asm ("ta 3");
 #endif
+#endif
   
   /* Save registers that we need to see on the stack.  We need to see
      registers used to hold register variables and registers used to
