--- src/filelock.c.orig	2008-01-07 23:30:11.000000000 -0500
+++ src/filelock.c	2010-02-12 18:40:07.000000000 -0500
@@ -64,7 +64,13 @@
 
 #ifdef CLASH_DETECTION
 
+#if __FreeBSD_version >= 900007
+#include <utmpx.h>
+#undef BOOT_TIME
+#define ut_time ut_tv.tv_sec
+#else
 #include <utmp.h>
+#endif
 
 #if !defined (S_ISLNK) && defined (S_IFLNK)
 #define S_ISLNK(m) (((m) & S_IFMT) == S_IFLNK)
@@ -253,13 +259,17 @@
    the first reboot record otherwise.
    Ignore all reboot records on or before BOOT_TIME.
    Success is indicated by setting BOOT_TIME to a larger value.  */
-
 void
 get_boot_time_1 (filename, newest)
      char *filename;
      int newest;
 {
+#if __FreeBSD_version >= 900007
+  struct utmpx ut, *utp;
+#else
   struct utmp ut, *utp;
+#endif
+
   int desc;
 
   if (filename)
