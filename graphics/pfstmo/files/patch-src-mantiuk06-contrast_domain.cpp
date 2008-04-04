--- src/mantiuk06/contrast_domain.cpp.orig	2008-03-12 09:20:28.000000000 +0000
+++ src/mantiuk06/contrast_domain.cpp	2008-03-12 09:27:16.000000000 +0000
@@ -58,6 +58,13 @@
 #define LOOKUP_W_TO_R 107
 
 
+#if defined(__FreeBSD__)
+static inline float exp10f(float x) {
+	return powf(10.,x);
+}
+#endif
+
+
 static void contrast_equalization( pyramid_t *pp, const float contrastFactor );
 
 static void transform_to_luminance(pyramid_t* pyramid, float* const x, progress_callback progress_cb, const bool bcg);
