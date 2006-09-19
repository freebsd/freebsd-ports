--- chu.c.orig	Wed Mar 17 11:42:18 1999
+++ chu.c	Mon Sep 18 17:46:42 2006
@@ -20,15 +20,21 @@
 #include <stdlib.h>
 #include <string.h>
 #include <math.h>
+#include <errno.h>
+#include <sys/types.h>
 #include <sys/time.h>
 #include <sys/resource.h>
 #include <unistd.h>
 
-#define USE_TIMEX
+#define ADJTIME
+#undef USE_TIMEX
+#define USE_ADJTIME
+
+#ifdef ADJTIME
 #ifdef USE_TIMEX
 #include <sys/timex.h>
 #endif
-
+#endif
 #define SAMPLE_RATE 8000
 #define SAMPLES 512
 #define OVERLAP 50
@@ -389,6 +395,21 @@
   }
 }
 
+#ifdef USE_ADJTIME
+void
+do_adjtime(int microsec)
+{
+  struct timeval delta;
+  int status;
+
+  printf("do_adjtime adjustment: %d\n", microsec);
+  delta.tv_sec = 0;
+  delta.tv_usec = microsec;
+  status = adjtime(&delta, NULL);
+  printf("do_adjtime status: %d\n", status);
+}
+#endif
+
 #ifdef USE_TIMEX
 void timex_adjustment(int microsec)
 {
@@ -462,7 +483,8 @@
   adjtimex(&t);
   offset = t.offset;
 #endif
-
+#ifdef USE_ADJTIME
+#endif
   return (double) offset; 
 }
 
@@ -655,12 +677,17 @@
     tv.tv_usec += 1000000;
   }
 
+#ifdef ADJTIME
 #ifdef USE_TIMEX
   if (fabs(d) < ((double)MAXPHASE))
   {
     timex_adjustment((int)-d);
   }
+#else
+  if (fabs(d) < ((double)1000000))
+    do_adjtime((int)-d);
   else
+#endif
 #endif
   {
     printf("standard adjustment ");
