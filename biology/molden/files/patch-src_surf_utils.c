- fix return statements in the function the returns int

--- src/surf/utils.c.orig	2022-07-15 23:20:39 UTC
+++ src/surf/utils.c
@@ -91,7 +91,7 @@ float			radius;
   disc = radius*radius - DOTPROD3(EO, EO);
   if (FP_EQ_EPS(disc, 0, GP_EPS*GP_EPS))
   { VEC3_ASN_OP(int_point, =, ray_pt);
-    return;
+    return -1;
   }
 
   one_by_sq_dir_mag = 1.0/DOTPROD3(ray_dir, ray_dir);
@@ -107,6 +107,7 @@ float			radius;
   { t = v*one_by_sq_dir_mag - sqrt(disc*one_by_sq_dir_mag);
     VEC3_V_OP_V_OP_S(int_point, ray_pt, +, ray_dir, *, t);
   }
+  return -1;
 }
 
 /*----------------------------------------------------------------------------------
