--- src/hf/hf_calc.c.orig	Tue Nov 22 07:25:40 2005
+++ src/hf/hf_calc.c	Mon Mar  6 13:08:02 2006
@@ -1298,6 +1298,8 @@
 		overflow);
 }
 
+#define lround(x) (((x) - (gdouble)(long int)(x)) < 0.5 ? (x) : (x+1.0))
+
 void hf_fast_rotate (hf_type *hf_in, hf_type *hf_out, gint hf_size, gint angle) {
 //	Rotation of a square HF, preview style, with aliasing
 //	"Wraps"
