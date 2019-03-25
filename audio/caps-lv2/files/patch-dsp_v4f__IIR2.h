--- dsp/v4f_IIR2.h.orig
+++ dsp/v4f_IIR2.h
@@ -45,8 +45,8 @@
 			{
 				v4f_t w = v4f_2pi * f;
 
-				sin = v4f_map<__builtin_sinf> (w);
-				cos = v4f_map<__builtin_cosf> (w);
+				sin = v4f_map<sinf> (w);
+				cos = v4f_map<cosf> (w);
 
 				alpha = sin / (v4f_2 * Q);
 			}
@@ -549,9 +549,9 @@
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
