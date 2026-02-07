--- mono/mini/driver.c.orig	2018-08-24 08:17:13.000000000 -0700
+++ mono/mini/driver.c	2021-11-27 20:03:33.006998000 -0800
@@ -16,6 +16,8 @@
 #include <signal.h>
 #endif
 #if HAVE_SCHED_SETAFFINITY
+#include <sys/param.h>
+#define _WITH_CPU_SET_T
 #include <sched.h>
 #endif
 #ifdef HAVE_UNISTD_H
@@ -1652,6 +1654,9 @@
 #if HAVE_SCHED_SETAFFINITY
 	if (!use_smp) {
 		unsigned long proc_mask = 1;
+#if defined(__FreeBSD_version) && __FreeBSD_version >= 1400042
+#undef GLIBC_BEFORE_2_3_4_SCHED_SETAFFINITY
+#endif
 #ifdef GLIBC_BEFORE_2_3_4_SCHED_SETAFFINITY
 		sched_setaffinity (getpid(), (gpointer)&proc_mask);
 #else
