--- gdb/i386bsd-nat.c       2003/01/02 20:22:00     1.1
+++ gdb/i386bsd-nat.c       2003/01/02 20:22:35
@@ -306,7 +306,7 @@
   /* For some mysterious reason, some of the reserved bits in the
      debug control register get set.  Mask these off, otherwise the
      ptrace call below will fail.  */
-  dbregs.dr7 &= ~(0x0000fc00);
+  DBREG_DRX ((&dbregs), 7) = ~(0x0000fc00);
 
   DBREG_DRX ((&dbregs), regnum) = value;
 
@@ -355,7 +355,7 @@
     return 0;
 #endif
 
-  return dbregs.dr6;
+  return DBREG_DRX ((&dbregs), 6);
 }
 
 #endif /* PT_GETDBREGS */
