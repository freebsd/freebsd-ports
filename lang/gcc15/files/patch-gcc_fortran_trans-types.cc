--- gcc/fortran/trans-types.cc.orig
+++ gcc/fortran/trans-types.cc
@@ -595,7 +595,8 @@
      precision.  For libgfortran calls pretend the IEEE 754 quad TFmode has
      kind 17 rather than 16 and use kind 16 for the IBM extended format
      TFmode.  */
-  if (composite_mode != QImode && saw_r16 && !MODE_COMPOSITE_P (r16_mode))
+  if (composite_mode != QImode && saw_r16 && !MODE_COMPOSITE_P (r16_mode)
+      && TARGET_GLIBC_MAJOR >= 2)
     {
       for (int i = 0; i < r_index; ++i)
 	if (gfc_real_kinds[i].kind == 16)
