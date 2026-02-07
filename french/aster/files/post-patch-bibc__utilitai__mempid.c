--- bibc/utilitai/mempid.c.orig	2020-10-20 16:45:20.000000000 +0200
+++ bibc/utilitai/mempid.c	2020-11-10 19:29:26.945762000 +0100
@@ -77,7 +77,7 @@
     kvm_close(kd);
 
     /* VmSize */
-    val[0] = B2K((uintmax_t)kp->ki_size);
+    val[0] = 0;
     /* VmPeak - not defined in /compat/linux/proc/pid/status */
     val[1] = -1;
     iret = 0;
