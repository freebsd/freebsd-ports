--- sysdeps/freebsd/mem.c.orig	Tue Jan 14 17:22:18 2003
+++ sysdeps/freebsd/mem.c	Tue Jan 14 17:22:28 2003
@@ -75,7 +75,7 @@
 
 /* MIB array for sysctl */
 static int mib_length=2;
-#ifdef __bsdi__
+#ifdef VM_METER
 static int mib [] = { CTL_VM, VM_TOTAL };
 #else
 static int mib [] = { CTL_VM, VM_METER };
