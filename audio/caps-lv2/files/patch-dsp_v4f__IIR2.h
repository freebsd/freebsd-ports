--- dsp/v4f_IIR2.h.orig	2019-03-22 09:42:59 UTC
+++ dsp/v4f_IIR2.h
@@ -32,9 +32,9 @@
 
 namespace DSP {
 
-#ifdef __APPLE__
+#ifdef __FreeBSD__
 
-inline float exp10f(float f) {return __exp10f(f);}
+inline float exp10f(float f) {return powf(10., f);}
 
 #endif
 
@@ -47,8 +47,8 @@ class RBJv4
 			{
 				v4f_t w = v4f_2pi * f;
 
-				sin = v4f_map<__builtin_sinf> (w);
-				cos = v4f_map<__builtin_cosf> (w);
+				sin = v4f_map<sinf> (w);
+				cos = v4f_map<cosf> (w);
 
 				alpha = sin / (v4f_2 * Q);
 			}
@@ -551,9 +551,9 @@ class Resonator4fBank
 			{
 				v4f_t * a = state + i*Item;
 				f *= v4f_2pi;
-				a[0] = v4f_map<__builtin_sinf> (f);
+				a[0] = v4f_map<sinf> (f);
 				a[0] *= gain;
-				a[5] = v4f_map<__builtin_cosf> (f);
+				a[5] = v4f_map<cosf> (f);
 				set_r (i, r);
 			}
 		void set_r (int i, v4f_t r)
