--- src/filelock.c.orig	2010-11-04 11:03:51.000000000 +0900
+++ src/filelock.c	2010-11-04 11:15:59.000000000 +0900
@@ -65,7 +65,13 @@
 
 #ifdef CLASH_DETECTION
 
+#if __FreeBSD_version >= 900007
+#include <utmpx.h>
+#undef BOOT_TIME
+#define ut_time ut_tv.tv_sec
+#else
 #include <utmp.h>
+#endif
 
 /* A file whose last-modified time is just after the most recent boot.
    Define this to be NULL to disable checking for this file.  */
@@ -256,7 +262,11 @@
      char *filename;
      int newest;
 {
+#if __FreeBSD_version >= 900007
+  struct utmpx ut, *utp;
+#else
   struct utmp ut, *utp;
+#endif
   int desc;
 
   if (filename)
