--- coregrind/vg_signals.c.orig	Mon Sep 19 21:16:07 2005
+++ coregrind/vg_signals.c	Mon Sep 19 21:28:05 2005
@@ -1488,6 +1488,15 @@
 	 VG_(start_GDB)( tid );
       }
 
+      if (core) {
+         static struct vki_rlimit zero = { 0, 0 };
+
+         VG_(message) (Vg_UserMsg, "Core dumping not implemented. Please re-run valgrind after fixing the crash.");
+
+         /* make sure we don't get a confusing kernel-generated coredump */
+         VG_(setrlimit)(VKI_RLIMIT_CORE, &zero);
+      }
+
       if (VG_(fatal_signal_set)) {
 	 VG_(fatal_sigNo) = sigNo;
 	 __builtin_longjmp(VG_(fatal_signal_jmpbuf), 1);
