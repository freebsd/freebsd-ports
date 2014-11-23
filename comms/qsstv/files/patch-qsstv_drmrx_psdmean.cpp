--- qsstv/drmrx/psdmean.cpp.orig	2014-04-08 02:02:47.000000000 -0700
+++ qsstv/drmrx/psdmean.cpp	2014-04-08 02:03:40.000000000 -0700
@@ -36,7 +36,6 @@
 #include <stdlib.h>
 #include <math.h>
 #include <sys/types.h>
-#include <malloc.h>
 void rfft(float *, int, int);
 void psdmean(float *input, float *psd, int lblock, int nblocks)
 {
