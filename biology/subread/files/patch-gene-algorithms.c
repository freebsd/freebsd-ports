--- gene-algorithms.c.orig	2020-06-04 23:57:31 UTC
+++ gene-algorithms.c
@@ -28,7 +28,7 @@
 #include <sys/stat.h>
 #include <sys/types.h>
 
-#ifndef FREEBSD
+#ifndef __FreeBSD__
 #include <sys/timeb.h>
 #endif
 
@@ -1563,7 +1563,7 @@ int load_offsets(gene_offset_t* offsets , const char i
 
 double miltime(){
 	double ret;
-	#ifdef FREEBSD
+	#ifdef __FreeBSD__
 	struct timeval tp;
 	struct timezone tz;
 	tz.tz_minuteswest=0;
