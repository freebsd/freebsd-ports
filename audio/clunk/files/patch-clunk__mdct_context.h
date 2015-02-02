--- clunk/mdct_context.h.orig	2014-09-29 10:48:48.000000000 +0400
+++ clunk/mdct_context.h	2015-01-23 14:14:23.000000000 +0300
@@ -61,7 +61,7 @@
 
 	T data[N];
 
-	mdct_context() : sqrt_N((T)sqrt((T)N)), data() {
+	mdct_context() : window_func(), sqrt_N((T)sqrt((T)N)), data() {
 		for(unsigned t = 0; t < N4; ++t) {
 			angle_cache[t] = std::polar<T>(1, 2 * T(M_PI) * (t + T(0.125)) / N);
 		}
