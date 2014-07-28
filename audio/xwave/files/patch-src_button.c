--- src/button.c.orig	Mon Nov  9 08:22:55 1998
+++ src/button.c	Fri Jun 30 19:49:16 2000
@@ -679,7 +679,7 @@
     now_clock=clock();
     sample_time=(float)md->wd->tlength/(float)md->wd->freq;
 
-#if defined(linux) || defined (FreeBSD) || defined(sun)
+#if defined(linux) || defined (__FreeBSD__) || defined(sun)
     gone_time=(float)(now_clock-start_clock)/(float)CLOCKS_PER_SEC;
 #elif defined(sgi)
     gone_time=(float)(now_clock-start_clock)/(float)750000;
