--- src/libcore/cmath.rs.orig	2012-02-02 09:08:04.690802969 +0800
+++ src/libcore/cmath.rs	2012-02-02 09:12:37.705978161 +0800
@@ -161,7 +161,6 @@
     #[link_name="sqrtf"] pure fn sqrt(n: c_float) -> c_float;
     #[link_name="tanf"] pure fn tan(n: c_float) -> c_float;
     #[link_name="tanhf"] pure fn tanh(n: c_float) -> c_float;
-    #[link_name="tgammaf"] pure fn tgamma(n: c_float) -> c_float;
     #[link_name="truncf"] pure fn trunc(n: c_float) -> c_float;
 }
 
