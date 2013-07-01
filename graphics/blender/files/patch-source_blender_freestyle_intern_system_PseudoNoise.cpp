--- source/blender/freestyle/intern/system/PseudoNoise.cpp.orig	2013-06-30 12:59:00.000000000 +0200
+++ source/blender/freestyle/intern/system/PseudoNoise.cpp	2013-06-30 13:03:36.000000000 +0200
@@ -46,7 +46,7 @@
 real PseudoNoise::linearNoise(real x)
 {
 	real tmp;
-	int i = abs(modf(x, &tmp)) * NB_VALUE_NOISE;
+	int i = (int)(fabs(modf(x, &tmp)) * NB_VALUE_NOISE);
 	real x1 = _values[i], x2 = _values[(i + 1) % NB_VALUE_NOISE];
 	real t = modf(x * NB_VALUE_NOISE, &tmp);
 	return x1 * (1 - t) + x2 * t;
@@ -64,7 +64,7 @@
 real PseudoNoise::smoothNoise(real x)
 {
 	real tmp;
-	int i = abs(modf(x, &tmp)) * NB_VALUE_NOISE;
+	int i = (int)(fabs(modf(x, &tmp)) * NB_VALUE_NOISE);
 	int h = i - 1;
 	if (h < 0) {
 		h = NB_VALUE_NOISE + h;
