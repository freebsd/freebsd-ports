--- coregrind/vg_signals.c.orig	Tue Aug 31 22:39:50 2004
+++ coregrind/vg_signals.c	Tue Aug 31 22:41:36 2004
@@ -1374,6 +1374,12 @@
 #define NT_PRXFPREG     0x46e62b7f      /* copied from gdb5.1/include/elf/common.h */
 #endif /* NT_PRXFPREG */
 
+// FIXME: Needed for FreeBSD 4, same ugly hack as in coregrind/ume.c XXX
+#ifndef ELFMAG
+#define ELFMAG "\177ELF"
+#define SELFMAG 4
+#endif
+
 /* If true, then this Segment may be mentioned in the core */
 static Bool may_dump(const Segment *seg)
 {
