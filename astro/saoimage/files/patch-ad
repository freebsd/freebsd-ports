--- disppsct.c.orig	Sun Jan 16 23:45:17 2000
+++ disppsct.c	Sun Jan 16 23:53:18 2000
@@ -598,7 +598,7 @@
   char *getenv();
 #endif
 
-#ifdef SUN
+#if defined(SUN) && !defined(__FreeBSD__)
   long time();		/* should be in time.h, but not in SunOS */
 #endif
   long clock;
