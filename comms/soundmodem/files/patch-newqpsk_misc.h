--- newqpsk/misc.h.orig	2002-08-09 15:01:52.000000000 -0500
+++ newqpsk/misc.h	2013-12-14 17:36:50.000000000 -0500
@@ -10,7 +10,7 @@
 /*
  * Hamming weight (number of bits that are ones).
  */
-extern inline unsigned int hweight32(unsigned int w) 
+static inline unsigned int hweight32(unsigned int w) 
 {
 	w = (w & 0x55555555) + ((w >>  1) & 0x55555555);
 	w = (w & 0x33333333) + ((w >>  2) & 0x33333333);
@@ -20,7 +20,7 @@
 	return w;
 }
 
-extern inline unsigned int hweight16(unsigned short w)
+static inline unsigned int hweight16(unsigned short w)
 {
 	w = (w & 0x5555) + ((w >> 1) & 0x5555);
 	w = (w & 0x3333) + ((w >> 2) & 0x3333);
@@ -29,7 +29,7 @@
 	return w;
 }
 
-extern inline unsigned int hweight8(unsigned char w)
+static inline unsigned int hweight8(unsigned char w)
 {
 	w = (w & 0x55) + ((w >> 1) & 0x55);
 	w = (w & 0x33) + ((w >> 2) & 0x33);
@@ -42,7 +42,7 @@
 /*
  * Reverse order of bits.
  */
-extern inline unsigned int rbits32(unsigned int w)
+static inline unsigned int rbits32(unsigned int w)
 {
 	w = ((w >>  1) & 0x55555555) | ((w <<  1) & 0xaaaaaaaa);
 	w = ((w >>  2) & 0x33333333) | ((w <<  2) & 0xcccccccc);
@@ -52,7 +52,7 @@
 	return w;
 }
 
-extern inline unsigned short rbits16(unsigned short w)
+static inline unsigned short rbits16(unsigned short w)
 {
 	w = ((w >> 1) & 0x5555) | ((w << 1) & 0xaaaa);
 	w = ((w >> 2) & 0x3333) | ((w << 2) & 0xcccc);
@@ -61,7 +61,7 @@
 	return w;
 }
 
-extern inline unsigned char rbits8(unsigned char w)
+static inline unsigned char rbits8(unsigned char w)
 {
 	w = ((w >> 1) & 0x55) | ((w << 1) & 0xaa);
 	w = ((w >> 2) & 0x33) | ((w << 2) & 0xcc);
@@ -71,7 +71,7 @@
 
 /* ---------------------------------------------------------------------- */
 
-extern inline float avg(float average, float input, int scale)
+static inline float avg(float average, float input, int scale)
 {
 	int i;
 
@@ -82,12 +82,12 @@
 	return (average + input);
 }
 
-extern inline float avg2(float average, float input, float weight)
+static inline float avg2(float average, float input, float weight)
 {
 	return input * weight + average * (1.0 - weight);
 }
 
-extern inline float phaseavg(float *data, int len)
+static inline float phaseavg(float *data, int len)
 {
 	float sum = 0.0;
 	float min = M_PI;
