--- src/libcore/cmath.rs.orig	2012-04-01 10:40:10.385607179 +0800
+++ src/libcore/cmath.rs	2012-04-01 10:40:34.370606102 +0800
@@ -164,7 +164,6 @@
     #[link_name="sqrtf"] pure fn sqrt(n: c_float) -> c_float;
     #[link_name="tanf"] pure fn tan(n: c_float) -> c_float;
     #[link_name="tanhf"] pure fn tanh(n: c_float) -> c_float;
-    #[link_name="tgammaf"] pure fn tgamma(n: c_float) -> c_float;
     #[link_name="truncf"] pure fn trunc(n: c_float) -> c_float;
 }
 
