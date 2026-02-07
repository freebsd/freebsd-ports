--- mono/utils/mono-proclib.c.orig	2018-08-24 08:17:13.000000000 -0700
+++ mono/utils/mono-proclib.c	2021-11-27 14:55:20.354869000 -0800
@@ -17,6 +17,7 @@
 #include <unistd.h>
 #endif
 #ifdef HAVE_SCHED_GETAFFINITY
+#define _WITH_CPU_SET_T
 #include <sched.h>
 #endif
 
