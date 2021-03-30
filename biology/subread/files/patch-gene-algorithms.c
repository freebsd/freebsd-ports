--- gene-algorithms.c.orig	2021-03-30 13:51:05 UTC
+++ gene-algorithms.c
@@ -29,7 +29,7 @@
 #include <sys/stat.h>
 #include <sys/types.h>
 
-#ifndef FREEBSD
+#ifndef __FreeBSD__
 #include <sys/timeb.h>
 #endif
 
@@ -1568,7 +1568,7 @@ int load_offsets(gene_offset_t* offsets , const char i
 
 double miltime(){
 	double ret;
-	#ifdef FREEBSD
+	#ifdef __FreeBSD__
 		struct timeval tp;
 		struct timezone tz;
 		tz.tz_minuteswest=0;
