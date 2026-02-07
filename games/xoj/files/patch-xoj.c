--- xoj.c.orig	Tue Jul 26 23:10:19 1994
+++ xoj.c	Fri Oct 13 22:37:45 2000
@@ -33,7 +33,9 @@
  
 #include <stdio.h>
 #include <math.h>
+#ifndef __STDC__
 #include <malloc.h>
+#endif
 #include <signal.h>
 #include <limits.h>
 
@@ -106,7 +108,9 @@
 void UpdateCop();
 void DrawCop();
 void EraseCop();
+#ifndef __FreeBSD__
 void usleep();
+#endif
 Pixel AllocNamedColor();
 
 void
@@ -584,6 +588,7 @@
 /*
  * sleep for a number of micro-seconds
  */
+#ifndef __FreeBSD__
 void usleep(usec) 
 unsigned long usec;
 {
@@ -596,6 +601,7 @@
     select(0, (void *)0, (void *)0, (void *)0, &t);
 #endif
 }
+#endif
 
 
 
