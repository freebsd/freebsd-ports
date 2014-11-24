--- qsstv/drmrx/deinterleaver.cpp.orig	2014-04-08 02:02:11.000000000 -0700
+++ qsstv/drmrx/deinterleaver.cpp	2014-04-08 02:03:30.000000000 -0700
@@ -30,7 +30,6 @@
 
 #include <stdio.h>
 #include <stdlib.h>
-#include <malloc.h>
 #include <math.h>
 int *deinterleaver(int xinA, int tA, int xinB, int tB)
 {
