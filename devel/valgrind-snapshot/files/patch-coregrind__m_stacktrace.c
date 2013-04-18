--- ./coregrind/m_stacktrace.c.orig	2013-04-18 16:40:39.221762499 -0500
+++ ./coregrind/m_stacktrace.c	2013-04-18 16:40:49.927758427 -0500
@@ -329,7 +329,7 @@
       if (filename != NULL && VG_(strstr)(filename, "/libc.so")) {
          match = 1;
       }
-      if (match = 1 && fp_min <= uregs.xsp &&
+      if (match == 1 && fp_min <= uregs.xsp &&
 	  uregs.xsp <= fp_max - 1 * sizeof(UWord)) {
          /* fp looks sane, so use it. */
          uregs.xip = (((UWord*)uregs.xsp)[0]);
