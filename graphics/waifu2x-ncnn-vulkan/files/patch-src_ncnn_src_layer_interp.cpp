--- src/ncnn/src/layer/interp.cpp.orig	2020-10-21 19:36:40 UTC
+++ src/ncnn/src/layer/interp.cpp
@@ -41,6 +41,12 @@ int Interp::load_param(const ParamDict& pd)
     return 0;
 }
 
+
+#if defined(__GNUC__) && defined(__powerpc__) && defined(__ALTIVEC__)
+// NOTE gcc altivec optimized version produce wrong result
+// so I have to disable vectorize here  --- nihui
+__attribute__((optimize("no-tree-vectorize")))
+#endif
 static void linear_coeffs(int w, int outw, int* xofs, float* alpha)
 {
     double scale = (double)w / outw;
