--- gdb/i386bsd-nat.c.orig	2010-10-21 11:18:03.171107000 -0400
+++ gdb/i386bsd-nat.c	2010-10-21 11:18:18.849642000 -0400
@@ -88,7 +88,7 @@
 
 /* Supply the general-purpose registers in GREGS, to REGCACHE.  */
 
-static void
+void
 i386bsd_supply_gregset (struct regcache *regcache, const void *gregs)
 {
   const char *regs = gregs;
@@ -107,7 +107,7 @@
    GREGS.  If REGNUM is -1, collect and store all appropriate
    registers.  */
 
-static void
+void
 i386bsd_collect_gregset (const struct regcache *regcache,
 			 void *gregs, int regnum)
 {
