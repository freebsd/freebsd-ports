--- src/libcore/f32.rs.orig	2012-02-02 09:20:38.079803515 +0800
+++ src/libcore/f32.rs	2012-02-02 09:20:53.241930085 +0800
@@ -9,6 +9,8 @@
 import cmath::c_float::*;
 import cmath::c_float_targ_consts::*;
 
+import cmath::c_double;
+
 type t = f32;
 
 // These are not defined inside consts:: for consistency with
@@ -247,6 +249,10 @@
     ret ln(n) / consts::ln_2;
 }
 
+pure fn tgamma(n: f32) -> f32 {
+    ret c_double::tgamma(n as f64) as f32;
+}
+
 //
 // Local Variables:
 // mode: rust
