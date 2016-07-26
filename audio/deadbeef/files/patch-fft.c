--- fft.c.orig	2016-04-24 21:38:13 UTC
+++ fft.c
@@ -27,6 +27,10 @@
 #include <math.h>
 #include <complex.h>
 
+#if __FreeBSD_version < 902000
+#  define cexpf(x) (expf(crealf(x))*(cosf(cimagf(x))+sinf(cimagf(x))*I))
+#endif
+
 #define N (DDB_FREQ_BANDS * 2)
 
 static float hamming[N];              /* hamming window, scaled to sum to 1 */
