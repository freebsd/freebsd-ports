--- src/wtmp.c.orig	2010-07-05 09:52:50.147213835 +0200
+++ src/wtmp.c	2010-07-05 09:53:25.075513542 +0200
@@ -126,7 +126,9 @@
   }
 
 #else /* Non-SVR4 systems */
+#if !defined(__FreeBSD_version) || __FreeBSD_version < 900007 || !defined(HAVE_UTMPX_H)
   struct utmp ut;
+#endif
   static int fd = -1;
 
   if (fd < 0 &&
