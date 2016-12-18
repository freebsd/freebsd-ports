--- gdb/x86bsd-nat.c.orig	2016-10-18 13:27:55.820837000 +0200
+++ gdb/x86bsd-nat.c	2016-10-18 13:29:02.518927000 +0200
@@ -82,7 +82,11 @@
   /* For some mysterious reason, some of the reserved bits in the
      debug control register get set.  Mask these off, otherwise the
      ptrace call below will fail.  */
+#ifdef __i386__
+  DBREG_DRX ((&dbregs), 7) &= ~(0x0000fc00);
+#else
   DBREG_DRX ((&dbregs), 7) &= ~(0xffffffff0000fc00);
+#endif 
 
   DBREG_DRX ((&dbregs), regnum) = value;
 
