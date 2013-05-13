
$FreeBSD$

--- src/filelock.c.orig
+++ src/filelock.c
@@ -64,7 +64,12 @@
 
 #ifdef CLASH_DETECTION
 
+#if __FreeBSD_version >= 900007
+#include <utmpx.h>
+#define ut_time ut_tv.tv_sec
+#else
 #include <utmp.h>
+#endif
 
 #if !defined (S_ISLNK) && defined (S_IFLNK)
 #define S_ISLNK(m) (((m) & S_IFMT) == S_IFLNK)
@@ -253,13 +258,17 @@
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
@@ -272,16 +281,28 @@
 
       emacs_close (desc);
 
+#if __FreeBSD_version >= 900007
+	  setutxdb (UTXDB_ACTIVE, filename);
+#else
       utmpname (filename);
+#endif
     }
 
+#if __FreeBSD_version >= 900007
+  setutxent ();
+#else
   setutent ();
+#endif
 
   while (1)
     {
       /* Find the next reboot record.  */
       ut.ut_type = BOOT_TIME;
+#if __FreeBSD_version >= 900007
+      utp = getutxid (&ut);
+#else
       utp = getutid (&ut);
+#endif
       if (! utp)
 	break;
       /* Compare reboot times and use the newest one.  */
@@ -293,11 +314,19 @@
 	}
       /* Advance on element in the file
 	 so that getutid won't repeat the same one.  */
+#if __FreeBSD_version >= 900007
+	  utp = getutxent ();
+#else
       utp = getutent ();
+#endif
       if (! utp)
 	break;
     }
+#if __FreeBSD_version >= 900007
+  endutxent();
+#else
   endutent ();
+#endif
 }
 #endif /* BOOT_TIME */
 
