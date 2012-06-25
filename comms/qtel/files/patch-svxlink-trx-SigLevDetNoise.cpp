--- ../svxlink-11.05.orig/svxlink/trx/SigLevDetNoise.cpp	2009-07-20 03:58:22.000000000 -0700
+++ svxlink/trx/SigLevDetNoise.cpp	2012-05-28 10:27:56.000000000 -0700
@@ -147,7 +147,7 @@
 void SigLevDetNoise::reset(void)
 {
   filter->reset();
-  last_siglev = pow10f(-offset / slope);
+  last_siglev = powf(10,-offset / slope);
 } /* SigLevDetNoise::reset */
 
 
