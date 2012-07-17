--- src/wtmp.c.orig	2011-05-23 23:22:24.000000000 +0200
+++ src/wtmp.c	2012-07-17 16:19:34.188505949 +0200
@@ -42,7 +42,7 @@
     !(defined(LINUX) || defined(__hpux) || defined (_AIX))
   /* This "auxilliary" utmp doesn't exist under linux. */
 
-#if defined(__sparcv9) && !defined(__NetBSD__)
+#if defined(__sparcv9) && !defined(__NetBSD__) && !defined(__FreeBSD__)
   struct futmpx utx;
   time_t t;
 
@@ -97,7 +97,7 @@
 #else /* SVR4 */
     utx.ut_syslen = strlen(utx.ut_host)+1;
 
-#  ifdef __sparcv9
+#  ifdef __sparcv9 && !defined(__FreeBSD__)
     time(&t);
     utx.ut_tv.tv_sec = (time32_t)t;
 #  else
@@ -126,7 +126,9 @@
   }
 
 #else /* Non-SVR4 systems */
+#if !defined(__FreeBSD_version) || __FreeBSD_version < 900007 || !defined(HAVE_UTMPX_H)
   struct utmp ut;
+#endif
   static int fd = -1;
 
   if (fd < 0 &&
