--- qsstv/drmrx/mkfacmap.cpp.orig	2014-04-08 02:02:22.000000000 -0700
+++ qsstv/drmrx/mkfacmap.cpp	2014-04-08 02:03:34.000000000 -0700
@@ -27,7 +27,6 @@
 
 #include <stdio.h>
 #include <stdlib.h>
-#include <malloc.h>
 int mkfacmap(int robustness_mode, int K_dc, int K_modulo, int /*@out@ */ *FACmap)
 {
   int elem_cnt, i;
