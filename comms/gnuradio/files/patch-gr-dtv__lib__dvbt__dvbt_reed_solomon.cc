--- gr-dtv/lib/dvbt/dvbt_reed_solomon.cc.orig	2015-08-05 18:54:39 UTC
+++ gr-dtv/lib/dvbt/dvbt_reed_solomon.cc
@@ -42,7 +42,7 @@ namespace gr {
       d_p = p; d_m = m;
 
       //maximum number of elements in the GF(p^m)
-      int q = powl(p, m);
+      int q = pow(p, m);
 
       d_gf_exp = new unsigned char[q];
       if (d_gf_exp == NULL) {
