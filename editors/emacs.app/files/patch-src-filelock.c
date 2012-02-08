--- src/filelock.c.orig	2006-03-11 05:06:04.000000000 +0100
+++ src/filelock.c	2012-02-08 07:11:31.000000000 +0100
@@ -63,7 +63,17 @@
 
 #ifdef CLASH_DETECTION
 
+#if __FreeBSD_version >= 900007
+#include <utmpx.h>
+#define ut_time ut_tv.tv_sec
+#define utmpname(f) setutxdb(UTXDB_LOG,f)
+#define setutent setutxent
+#define getutent getutxent
+#define endutent endutxent
+#define getutid getutxid
+#else
 #include <utmp.h>
+#endif
 
 #if !defined (S_ISLNK) && defined (S_IFLNK)
 #define S_ISLNK(m) (((m) & S_IFMT) == S_IFLNK)
@@ -252,13 +262,17 @@
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
