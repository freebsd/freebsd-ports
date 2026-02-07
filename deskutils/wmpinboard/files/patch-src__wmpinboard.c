--- wmpinboard.c.orig	Fri Dec  8 20:42:23 2000
+++ src/wmpinboard.c	Wed Nov 24 02:05:22 2004
@@ -10,6 +10,7 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <time.h>
+#include <sys/types.h>
 #include <sys/stat.h>
 #include <sys/time.h>
 
@@ -165,7 +166,7 @@
   char t[STRING_BUF_SIZE];
   FILE *file;
   int pid = (int) getpid();
-  static int sizes[6];
+  static int sizes[7];
   sizes[0] = size_0;
   sizes[1] = size_1;
   sizes[2] = size_2;
@@ -1141,13 +1142,7 @@
 void
 timer(unsigned int intv)
 {
-#ifndef __GLIBC__
-  struct itimerval val = { { 0, intv }, { 0, intv } };
-
-  setitimer(ITIMER_REAL, &val, 0);
-#else
   ualarm(intv, intv);
-#endif
 }
 
 /*
