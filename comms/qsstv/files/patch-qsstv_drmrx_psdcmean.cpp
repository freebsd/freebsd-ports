--- qsstv/drmrx/psdcmean.cpp.orig	2014-04-08 02:02:38.000000000 -0700
+++ qsstv/drmrx/psdcmean.cpp	2014-04-08 02:03:38.000000000 -0700
@@ -36,7 +36,6 @@
 #include <stdlib.h>
 #include <math.h>
 #include <sys/types.h>
-#include <malloc.h>
 void cfft(float *, int, int);
 void psdcmean(float *rsbuf, float *cpsd, int lblock, int nblocks)
 {
