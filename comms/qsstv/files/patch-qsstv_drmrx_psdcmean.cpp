--- qsstv/drmrx/psdcmean.cpp.orig	2016-04-08 23:08:29 UTC
+++ qsstv/drmrx/psdcmean.cpp
@@ -36,7 +36,6 @@
 #include <stdlib.h>
 #include <math.h>
 #include <sys/types.h>
-#include <malloc.h>
 void cfft(float *, int, int);
 void psdcmean(float *rsbuf, float *cpsd, int lblock, int nblocks)
 {
