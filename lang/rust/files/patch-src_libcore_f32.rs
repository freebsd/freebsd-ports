--- src/libcore/f32.rs.orig	2012-04-01 10:40:20.915606509 +0800
+++ src/libcore/f32.rs	2012-04-01 10:43:43.847606825 +0800
@@ -5,6 +5,8 @@
 import cmath::c_float::*;
 import cmath::c_float_targ_consts::*;
 
+import cmath::c_double;
+
 // FIXME find out why these have to be exported explicitly
 
 export add, sub, mul, div, rem, lt, le, gt, eq, eq, ne;
@@ -176,6 +178,10 @@
     ret ln(n) / consts::ln_2;
 }
 
+pure fn tgamma(n: f32) -> f32 {
+    ret c_double::tgamma(n as f64) as f32;
+}
+
 //
 // Local Variables:
 // mode: rust
