--- src/wtmp.c.orig	2012-08-04 08:45:32.292505678 +0200
+++ src/wtmp.c	2012-08-04 08:45:35.508505108 +0200
@@ -97,7 +97,7 @@
 #else /* SVR4 */
     utx.ut_syslen = strlen(utx.ut_host)+1;
 
-#  ifdef __sparcv9
+#  ifdef __sparcv9 && !defined(__FreeBSD__)
     time(&t);
     utx.ut_tv.tv_sec = (time32_t)t;
 #  else
