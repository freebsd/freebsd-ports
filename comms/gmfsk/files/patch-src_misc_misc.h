--- src/misc/misc.h.orig	2004-04-13 05:45:19.000000000 -0700
+++ src/misc/misc.h	2014-06-21 03:17:38.000000000 -0700
@@ -27,12 +27,21 @@
 
 #include <math.h>
 
+#ifdef __OPTIMIZE__
+#define INLINE_EXTERN	static inline
+#else
+#define INLINE_EXTERN	extern
+#endif
+
 /* ---------------------------------------------------------------------- */
 
 /*
  * Hamming weight (number of bits that are ones).
  */
-extern inline unsigned int hweight32(unsigned int w) 
+INLINE_EXTERN unsigned int hweight32(unsigned int w) 
+#ifndef __OPTIMIZE__
+;
+#else
 {
 	w = (w & 0x55555555) + ((w >>  1) & 0x55555555);
 	w = (w & 0x33333333) + ((w >>  2) & 0x33333333);
@@ -41,8 +50,12 @@
 	w = (w & 0x0000FFFF) + ((w >> 16) & 0x0000FFFF);
 	return w;
 }
+#endif
 
-extern inline unsigned int hweight16(unsigned short w)
+INLINE_EXTERN unsigned int hweight16(unsigned short w)
+#ifndef __OPTIMIZE__
+;
+#else
 {
 	w = (w & 0x5555) + ((w >> 1) & 0x5555);
 	w = (w & 0x3333) + ((w >> 2) & 0x3333);
@@ -50,31 +63,43 @@
 	w = (w & 0x00FF) + ((w >> 8) & 0x00FF);
 	return w;
 }
+#endif
 
-extern inline unsigned int hweight8(unsigned char w)
+INLINE_EXTERN unsigned int hweight8(unsigned char w)
+#ifndef __OPTIMIZE__
+;
+#else
 {
 	w = (w & 0x55) + ((w >> 1) & 0x55);
 	w = (w & 0x33) + ((w >> 2) & 0x33);
 	w = (w & 0x0F) + ((w >> 4) & 0x0F);
 	return w;
 }
+#endif
 
 /* ---------------------------------------------------------------------- */
 
 /*
  * Parity function. Return one if `w' has odd number of ones, zero otherwise.
  */
-extern inline int parity(unsigned int w)
+INLINE_EXTERN int parity(unsigned int w)
+#ifndef __OPTIMIZE__
+;
+#else
 {
 	return hweight32(w) & 1;
 }
+#endif
 
 /* ---------------------------------------------------------------------- */
 
 /*
  * Reverse order of bits.
  */
-extern inline unsigned int rbits32(unsigned int w)
+INLINE_EXTERN unsigned int rbits32(unsigned int w)
+#ifndef __OPTIMIZE__
+;
+#else
 {
 	w = ((w >>  1) & 0x55555555) | ((w <<  1) & 0xAAAAAAAA);
 	w = ((w >>  2) & 0x33333333) | ((w <<  2) & 0xCCCCCCCC);
@@ -83,8 +108,12 @@
 	w = ((w >> 16) & 0x0000FFFF) | ((w << 16) & 0xFFFF0000);
 	return w;
 }
+#endif
 
-extern inline unsigned short rbits16(unsigned short w)
+INLINE_EXTERN unsigned short rbits16(unsigned short w)
+#ifndef __OPTIMIZE__
+;
+#else
 {
 	w = ((w >> 1) & 0x5555) | ((w << 1) & 0xAAAA);
 	w = ((w >> 2) & 0x3333) | ((w << 2) & 0xCCCC);
@@ -92,21 +121,29 @@
 	w = ((w >> 8) & 0x00FF) | ((w << 8) & 0xFF00);
 	return w;
 }
+#endif
 
-extern inline unsigned char rbits8(unsigned char w)
+INLINE_EXTERN unsigned char rbits8(unsigned char w)
+#ifndef __OPTIMIZE__
+;
+#else
 {
 	w = ((w >> 1) & 0x55) | ((w << 1) & 0xFF);
 	w = ((w >> 2) & 0x33) | ((w << 2) & 0xCC);
 	w = ((w >> 4) & 0x0F) | ((w << 4) & 0xF0);
 	return w;
 }
+#endif
 
 /* ---------------------------------------------------------------------- */
-
+#ifndef FBSD_HAS_LOG2
 /*
  * Integer base-2 logarithm
  */
-extern inline int log2(unsigned int x)
+INLINE_EXTERN int log2(unsigned int x)
+#ifndef __OPTIMIZE__
+;
+#else
 {
 	int y = 0;
 
@@ -119,13 +156,17 @@
 
 	return y;
 }
-
+#endif
+#endif
 /* ---------------------------------------------------------------------- */
 
 /*
  * Gray encoding and decoding (8 bit)
  */
-extern inline unsigned char grayencode(unsigned char data)
+INLINE_EXTERN unsigned char grayencode(unsigned char data)
+#ifndef __OPTIMIZE__
+;
+#else
 {
 	unsigned char bits = data;
 
@@ -139,50 +180,75 @@
 
 	return bits;
 }
+#endif
 
-extern inline unsigned char graydecode(unsigned char data)
+INLINE_EXTERN unsigned char graydecode(unsigned char data)
+#ifndef __OPTIMIZE__
+;
+#else
 {
 	return data ^ (data >> 1);
 }
+#endif
 
 /* ---------------------------------------------------------------------- */
 
 /*
  * Hamming window function
  */
-extern inline double hamming(double x)
+INLINE_EXTERN double hamming(double x)
+#ifndef __OPTIMIZE__
+;
+#else
 {
         return 0.54 - 0.46 * cos(2 * M_PI * x);
 }
+#endif
 
 /* ---------------------------------------------------------------------- */
 
 /*
  * Sinc etc...
  */
-extern inline double sinc(double x)
+INLINE_EXTERN double sinc(double x)
+#ifndef __OPTIMIZE__
+;
+#else
 {
 	return (fabs(x) < 1e-10) ? 1.0 : (sin(M_PI * x) / (M_PI * x));
 }
+#endif
 
-extern inline double cosc(double x)
+INLINE_EXTERN double cosc(double x)
+#ifndef __OPTIMIZE__
+;
+#else
 {
 	return (fabs(x) < 1e-10) ? 0.0 : ((1.0 - cos(M_PI * x)) / (M_PI * x));
 }
+#endif
 
 /* ---------------------------------------------------------------------- */
 
-extern inline float clamp(float x, float min, float max)
+INLINE_EXTERN float clamp(float x, float min, float max)
+#ifndef __OPTIMIZE__
+;
+#else
 {
 	return (x < min) ? min : ((x > max) ? max : x);
 }
+#endif
 
 /* ---------------------------------------------------------------------- */
 
-extern inline float decayavg(float average, float input, float weight)
+INLINE_EXTERN float decayavg(float average, float input, float weight)
+#ifndef __OPTIMIZE__
+;
+#else
 {
 	return input * (1.0 / weight) + average * (1.0 - (1.0 / weight));
 }
+#endif
 
 /* ---------------------------------------------------------------------- */
 
