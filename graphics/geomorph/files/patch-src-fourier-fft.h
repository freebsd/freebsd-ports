--- src/fourier/fft.h.orig	2007-12-03 06:52:12.000000000 +0300
+++ src/fourier/fft.h	2008-08-02 18:46:31.000000000 +0400
@@ -25,14 +25,7 @@
 #define FFT_H
 #include <stdlib.h>
 #include <complex.h>
-
-#ifndef u_int
-	#define u_int unsigned int
-#endif
-
-#ifndef u_char
-	#define u_char unsigned char
-#endif
+#include <sys/types.h>
 
 // Module computation
 
