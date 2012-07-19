--- src/libcore/f32.rs.orig	2012-07-16 17:14:25.444144084 +0800
+++ src/libcore/f32.rs	2012-07-16 17:15:29.799514797 +0800
@@ -5,6 +5,8 @@
 import cmath::c_float::*;
 import cmath::c_float_targ_consts::*;
 
+import cmath::c_double;
+
 export add, sub, mul, div, rem, lt, le, gt, eq, ne;
 export is_positive, is_negative, is_nonpositive, is_nonnegative;
 export is_zero, is_infinite, is_finite;
@@ -179,6 +181,10 @@
     fn from_int(n: int) -> f32 { ret n as f32;    }
 }
 
+pure fn tgamma(n: f32) -> f32 {
+    ret c_double::tgamma(n as f64) as f32;
+}
+
 //
 // Local Variables:
 // mode: rust
