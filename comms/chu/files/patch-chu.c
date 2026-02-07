--- chu.c.orig	1999-03-17 16:42:18 UTC
+++ chu.c
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
@@ -389,6 +395,21 @@ void saveAdjTime()
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
@@ -462,7 +483,8 @@ double gettimexoffset()
   adjtimex(&t);
   offset = t.offset;
 #endif
-
+#ifdef USE_ADJTIME
+#endif
   return (double) offset; 
 }
 
@@ -655,13 +677,18 @@ void adj_time(double d)
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
 #endif
+#endif
   {
     printf("standard adjustment ");
 
@@ -1267,7 +1294,7 @@ char *parseArgs(int argc, char **argv)
   return fname;
 }
 
-void main(int argc, char **argv)
+int main(int argc, char **argv)
 {
   FILE *fp;
   signed char buf[8192];
@@ -1278,7 +1305,7 @@ void main(int argc, char **argv)
 
   fname = parseArgs(argc, argv);
   if (fname == NULL)
-    return;
+    return 0;
 
   /* Set priority to maximum -- just long enough for us
      to open the audio device and timestamp it.  This should
@@ -1293,7 +1320,7 @@ void main(int argc, char **argv)
   if (fp == NULL)
   {
     printf("fopen(): Unable to open file: %s  %s\n", fname, strerror(errno));
-    return;
+    return 0;
   }
 
   gettimeofday(&starttime, &tz);
