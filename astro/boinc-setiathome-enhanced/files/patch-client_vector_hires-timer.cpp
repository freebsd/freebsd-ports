--- client/vector/hires_timer.cpp.orig	2008-09-09 18:55:19.000000000 +0200
+++ client/vector/hires_timer.cpp	2010-10-23 00:05:28.000000000 +0200
@@ -56,6 +56,7 @@
 #include <sys/param.h>
 #endif
 #ifdef HAVE_SYS_SYSTM_H
+#include <sys/types.h>
 #include <sys/systm.h>
 #endif
 #ifdef HAVE_MACHINE_CPU_H
