--- cutil.c.orig	Mon Dec 11 10:38:11 2006
+++ cutil.c	Mon Dec 11 10:38:36 2006
@@ -67,7 +67,11 @@
   printf("\n\n");
   exit(*n);
 }
-
+struct tm *
+gmtime_r_(const time_t *clock, struct tm *result)
+{
+  gmtime_r(clock, result);
+}
 time_t time_(void)
 {
      return time(0);
