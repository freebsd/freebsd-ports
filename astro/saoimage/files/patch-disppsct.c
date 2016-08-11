--- disppsct.c.orig	2003-09-03 18:23:08 UTC
+++ disppsct.c
@@ -599,7 +599,7 @@ static char *make_label()
   char *getenv();
 #endif
 
-#ifdef SUN
+#if defined(SUN) && !defined(__FreeBSD__)
   long time();		/* should be in time.h, but not in SunOS */
 #endif
   long clock;
