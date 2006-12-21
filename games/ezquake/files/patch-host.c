--- host.c.orig	Tue Dec 19 19:51:09 2006
+++ host.c	Tue Dec 19 19:51:13 2006
@@ -249,7 +249,7 @@
 
 #ifdef __i386__
 	unsigned long long old_tsc, tsc_freq;
-	struct timeval tp, tp_old;
+	struct timeval tp, old_tp;
 #endif
 
 	mib[0] = CTL_HW;
