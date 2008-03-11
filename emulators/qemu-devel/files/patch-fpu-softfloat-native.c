Index: qemu/fpu/softfloat-native.c
@@ -228,7 +228,15 @@
 *----------------------------------------------------------------------------*/
 float64 float64_trunc_to_int( float64 a STATUS_PARAM )
 {
+#if defined(__FreeBSD__) && __FreeBSD__ <= 4
+    float64 ret;
+    fpsetround(FP_RZ);
+    ret = rint(a);
+    fpsetround(STATUS(float_rounding_mode));
+    return ret;
+#else
     return trunc(a);
+#endif
 }
 
 float64 float64_round_to_int( float64 a STATUS_PARAM )
