--- lib/kissfft/kiss_fft.h.orig	2009-08-06 16:11:34.000000000 +0900
+++ lib/kissfft/kiss_fft.h	2009-10-09 01:36:38.000000000 +0900
@@ -5,9 +5,6 @@
 #include <stdio.h>
 #include <math.h>
 #include <memory.h>
-#ifndef __APPLE__
-#include <malloc.h>
-#endif
 
 #ifdef __cplusplus
 extern "C" {
