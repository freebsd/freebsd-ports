--- dsp/v4f.h.orig	2019-03-22 09:42:59 UTC
+++ dsp/v4f.h
@@ -155,10 +155,10 @@ class Sin4f
 			{
 				v4f_t *y = data();
 				v4f_t w = -v4f_pi * f;
-				y[0] = v4f_map<__builtin_sinf> (w);
-				y[1] = v4f_map<__builtin_sinf> (v4f_2 * w);
+				y[0] = v4f_map<sinf> (w);
+				y[1] = v4f_map<sinf> (v4f_2 * w);
 				/* b in above scalar implementation is y[2] in the flat data */
-				y[2] = v4f_2 * v4f_map<__builtin_cosf> (w); /* b */
+				y[2] = v4f_2 * v4f_map<cosf> (w); /* b */
 				z = 0;
 			}
 
