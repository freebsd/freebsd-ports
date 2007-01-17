--- iodbc/trace/trace.c.orig	Wed Jan  3 23:21:46 2007
+++ iodbc/trace/trace.c	Wed Jan 10 16:04:57 2007
@@ -670,6 +670,10 @@
   extern char *odbcapi_symtab[];
   char *ptr = "invalid retcode";
 
+#ifdef HAVE_GETTIMEOFDAY
+  struct timeval tv;
+#endif
+
   /*
    * Guard against tracefile getting too big
    */
@@ -684,8 +688,6 @@
    * Calculate timestamp
    */
 #ifdef HAVE_GETTIMEOFDAY
-  struct timeval tv;
-
   gettimeofday (&tv, NULL);
   tv.tv_sec -= starttime.tv_sec;
   tv.tv_usec -= starttime.tv_usec;
