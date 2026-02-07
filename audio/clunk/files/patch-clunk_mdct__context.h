--- clunk/mdct_context.h.orig	2014-09-29 06:48:48 UTC
+++ clunk/mdct_context.h
@@ -61,7 +61,7 @@ public:
 
 	T data[N];
 
-	mdct_context() : sqrt_N((T)sqrt((T)N)), data() {
+	mdct_context() : window_func(), sqrt_N((T)sqrt((T)N)), data() {
 		for(unsigned t = 0; t < N4; ++t) {
 			angle_cache[t] = std::polar<T>(1, 2 * T(M_PI) * (t + T(0.125)) / N);
 		}
