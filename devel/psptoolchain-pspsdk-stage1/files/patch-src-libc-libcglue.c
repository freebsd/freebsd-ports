--- src/libc/libcglue.c.orig	2009-02-23 12:12:45.000000000 +0100
+++ src/libc/libcglue.c	2009-02-23 12:11:39.000000000 +0100
@@ -42,7 +42,7 @@
 
 /* If we're being built for PSPSDK's libc this function isn't defined. */
 #ifdef F_glue_gettimeofday
-int gettimeofday(struct timeval *tp, void *tzp)
+int gettimeofday(struct timeval *tp, struct timezone *tzp)
 {
 	return sceKernelLibcGettimeofday(tp, tzp);
 }
