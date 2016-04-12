--- qsstv/drmrx/mkfacmap.cpp.orig	2016-04-08 23:08:29 UTC
+++ qsstv/drmrx/mkfacmap.cpp
@@ -27,7 +27,6 @@
 
 #include <stdio.h>
 #include <stdlib.h>
-#include <malloc.h>
 int mkfacmap(int robustness_mode, int K_dc, int K_modulo, int /*@out@ */ *FACmap)
 {
   int elem_cnt, i;
