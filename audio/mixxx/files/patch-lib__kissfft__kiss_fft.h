--- lib/kissfft/kiss_fft.h.orig	2011-12-24 11:53:19.000000000 +0900
+++ lib/kissfft/kiss_fft.h	2012-01-16 06:10:09.000000000 +0900
@@ -5,9 +5,6 @@
 #include <stdio.h>
 #include <math.h>
 #include <memory.h>
-#ifndef __APPLE__
-#include <malloc.h>
-#endif
 
 #ifdef __cplusplus
 extern "C" {
