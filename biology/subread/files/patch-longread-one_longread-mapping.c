--- longread-one/longread-mapping.c.orig	2019-09-04 04:22:49 UTC
+++ longread-one/longread-mapping.c
@@ -30,7 +30,9 @@
 #ifndef __MINGW32__
 #include <sys/resource.h>
 #endif
+#ifndef __FreeBSD__	// Deprecated on FreeBSD
 #include <sys/timeb.h>
+#endif
 #include <sys/stat.h>
 #include <locale.h>
 #include <ctype.h>
@@ -223,9 +225,24 @@ int LRMvalidate_and_init_context(LRMcontext_t ** conte
 
 double LRMmiltime(){
 	double ret;
+
+/* Why not use gettimeofday() on all platforms? */
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
 	struct timeb trp;
 	ftime(&trp);
 	ret = trp.time*1.0+(trp.millitm*1.0/1000.0);
+
+#endif
 	return ret;
 }
 
