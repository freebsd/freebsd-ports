--- src/button.c.orig	1998-11-08 23:22:55 UTC
+++ src/button.c
@@ -679,7 +679,7 @@ Boolean set_playline(XtPointer client_da
     now_clock=clock();
     sample_time=(float)md->wd->tlength/(float)md->wd->freq;
 
-#if defined(linux) || defined (FreeBSD) || defined(sun)
+#if defined(linux) || defined (__FreeBSD__) || defined(sun)
     gone_time=(float)(now_clock-start_clock)/(float)CLOCKS_PER_SEC;
 #elif defined(sgi)
     gone_time=(float)(now_clock-start_clock)/(float)750000;
