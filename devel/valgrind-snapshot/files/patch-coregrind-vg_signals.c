--- coregrind/vg_signals.c.orig	Sun May  9 13:00:57 2004
+++ coregrind/vg_signals.c	Mon Sep 19 18:18:07 2005
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
@@ -1900,8 +1906,8 @@
       if (core) {
 	 static struct vki_rlimit zero = { 0, 0 };
 
-	 make_coredump(tid, info, corelim.rlim_cur);
-
+	 // make_coredump(tid, info, corelim.rlim_cur);
+	VG_(message) (Vg_UserMsg, "Core dumping is broken on FreeBSD. Please re-run valgrind after fixing the crash.");
 	 /* make sure we don't get a confusing kernel-generated coredump */
 	 VG_(setrlimit)(VKI_RLIMIT_CORE, &zero);
       }
