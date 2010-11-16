--- gdb/i386bsd-nat.h.orig	2010-10-21 11:18:08.097659000 -0400
+++ gdb/i386bsd-nat.h	2010-10-21 11:20:49.341989000 -0400
@@ -35,4 +35,12 @@
 
 extern unsigned long i386bsd_dr_get_status (void);
 
+/* low level i386 register functions used in i386fbsd-nat.c. */
+
+extern void i386bsd_supply_gregset (struct regcache *regcache,
+				    const void *gregs);
+
+extern void i386bsd_collect_gregset (const struct regcache *regcache,
+				     void *gregs, int regnum);
+
 #endif /* i386bsd-nat.h */
