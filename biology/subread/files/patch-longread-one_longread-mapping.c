--- longread-one/longread-mapping.c.orig	2021-03-30 13:58:29 UTC
+++ longread-one/longread-mapping.c
@@ -30,7 +30,9 @@
 #ifndef __MINGW32__
 #include <sys/resource.h>
 #endif
+#ifndef __FreeBSD__
 #include <sys/timeb.h>
+#endif
 #include <sys/stat.h>
 #include <locale.h>
 #include <ctype.h>
@@ -225,6 +227,17 @@ int LRMvalidate_and_init_context(LRMcontext_t ** conte
 #endif
 double LRMmiltime(){
 	double ret;
+#ifdef __FreeBSD__
+
+	struct timeval tp;
+	struct timezone tz;
+	tz.tz_minuteswest=0;
+	tz.tz_dsttime=0;
+	gettimeofday(&tp,&tz);
+	ret = tp.tv_sec+ 0.001*0.001* tp.tv_usec; 
+
+#else
+
 	#ifdef LRM_CLOCK_USE_GETTIME
 	struct timespec tsc;
 	clock_gettime(CLOCK_REALTIME, &tsc);
@@ -235,6 +248,7 @@ double LRMmiltime(){
 	ret = trp.time*1.0+(trp.millitm*1.0/1000.0);
 	#endif
 
+#endif
 	return ret;
 }
 
