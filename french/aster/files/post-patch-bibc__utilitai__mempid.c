--- bibc/utilitai/mempid.c.orig	2019-09-25 21:45:54.000000000 +0200
+++ bibc/utilitai/mempid.c	2020-01-02 22:28:47.035670000 +0100
@@ -77,7 +77,11 @@
     kvm_close(kd);
 
     /* VmSize */
+# if __FreeBSD_version > 1300000
+    val[0] = 0;
+# else
     val[0] = B2K((uintmax_t)kp->ki_size);
+# endif
     /* VmPeak - not defined in /compat/linux/proc/pid/status */
     val[1] = -1;
     iret = 0;
