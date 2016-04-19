--- qsstv/drmrx/psdmean.cpp.orig	2016-04-08 23:08:29 UTC
+++ qsstv/drmrx/psdmean.cpp
@@ -36,7 +36,6 @@
 #include <stdlib.h>
 #include <math.h>
 #include <sys/types.h>
-#include <malloc.h>
 void rfft(float *, int, int);
 void psdmean(float *input, float *psd, int lblock, int nblocks)
 {
