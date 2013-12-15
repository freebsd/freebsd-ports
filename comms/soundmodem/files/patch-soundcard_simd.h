--- soundcard/simd.h.orig	2002-08-09 15:01:52.000000000 -0500
+++ soundcard/simd.h	2013-12-14 17:34:29.000000000 -0500
@@ -54,16 +54,16 @@
 
 #if !defined(USEMMX) && !defined(USEVIS)
 
-extern inline void initsimd(int enable)
+static inline void initsimd(int enable)
 {
 }
 
-extern inline int checksimd(void)
+static inline int checksimd(void)
 {
 	return 0;
 }
 
-extern inline int simdfir16(const int16_t *p1, const int16_t *p2, unsigned int nr)
+static inline int simdfir16(const int16_t *p1, const int16_t *p2, unsigned int nr)
 {
 	int s = 0;
 
@@ -72,7 +72,7 @@
 	return s;
 }
 
-extern inline void simdpreparefpu(void)
+static inline void simdpreparefpu(void)
 {
 }
 
@@ -80,9 +80,9 @@
 
 extern unsigned int simd_enabled;
 
-extern void initsimd(int enable);
+void initsimd(int enable);
 
-extern inline int checksimd(void)
+static inline int checksimd(void)
 {
 	return simd_enabled;
 }
@@ -91,7 +91,7 @@
 
 #define MMXCLOBBER "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)"
 
-extern inline int simdfir16(const int16_t *p1, const int16_t *p2, unsigned int nr)
+static inline int simdfir16(const int16_t *p1, const int16_t *p2, unsigned int nr)
 {
 	unsigned int i, j;
 	int s = 0;
@@ -114,7 +114,7 @@
 	return s;
 }
 
-extern inline void simdpreparefpu(void)
+static inline void simdpreparefpu(void)
 {
 	if (checksimd())
 		asm volatile("emms");
@@ -122,7 +122,7 @@
 
 #elif defined(USEVIS)
 
-/*extern inline*/static int simdfir16(const int16_t *p1, const int16_t *p2, unsigned int nr)
+/*extern static inline*/static int simdfir16(const int16_t *p1, const int16_t *p2, unsigned int nr)
 {
 	double dsum1, dsum2, dsum3, dsum4, arg1, arg2, arg3, arg4;
 	float sum, sum1, sum2;
@@ -157,7 +157,7 @@
 	return s;
 }
 
-extern inline void simdpreparefpu(void)
+static inline void simdpreparefpu(void)
 {
 }
 
