from astro/p5-Astro-FITS-CFITSIO build log:

/usr/local/include/fitsio2.h:271:5: error: invalid token at start of a preprocessor expression
#if MACHINE == CRAY
    ^
/usr/include/machine/param.h:59:18: note: expanded from macro 'MACHINE'
#define MACHINE         "amd64"
                        ^

--- fitsio2.h.orig	2023-07-21 14:37:17 UTC
+++ fitsio2.h
@@ -268,14 +268,14 @@ extern int Fitsio_Pthread_Status;
  
 #endif
  
-#if MACHINE == CRAY
+#if 0
     /*
       Cray machines:   the large negative integer corresponds
       to the 3 most sig digits set to 1.   If these
       3 bits are set in a floating point number (64 bits), then it represents
       a reserved value (i.e., a NaN)
     */
-#define fnan(L) ( (L) >= 0xE000000000000000 ? 1 : 0) )
+#define fnan(L) ( (L) >= 0xE000000000000000 ? 1 : 0)
  
 #else
     /* these functions work for both big and little endian machines */
