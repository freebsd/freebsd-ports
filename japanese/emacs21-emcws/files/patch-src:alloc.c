--- src/alloc.c.orig	Thu Sep 12 13:50:01 2002
+++ src/alloc.c	Thu Sep 12 13:48:11 2002
@@ -3723,7 +3723,11 @@
   /* This trick flushes the register windows so that all the state of
      the process is contained in the stack.  */
 #ifdef sparc
+#ifdef __sparc64__
+  asm ("flushw");
+#else
   asm ("ta 3");
+#endif
 #endif
   
   /* Save registers that we need to see on the stack.  We need to see
