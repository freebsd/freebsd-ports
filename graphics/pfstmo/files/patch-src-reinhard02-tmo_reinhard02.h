--- src/reinhard02/tmo_reinhard02.h.orig	2008-09-04 12:46:49.000000000 +0000
+++ src/reinhard02/tmo_reinhard02.h	2014-06-18 15:29:52.328951402 +0000
@@ -13,8 +13,6 @@
 /*
  * @brief Photographic tone-reproduction
  *
- * @param width image width
- * @param height image height
  * @param Y input luminance
  * @param L output tonemapped intensities
  * @param use_scales true: local version, false: global version of TMO
@@ -23,10 +21,12 @@
  * @param num number of scales to use in computation (default: 8)
  * @param low size in pixels of smallest scale (should be kept at 1)
  * @param high size in pixels of largest scale (default 1.6^8 = 43)
+ * @param temporal_coherent tone mapping is time coherent for video sequences
+ * @param border relative width of image area scaled to midtone separately (default: 0 - use key for whole image)
  */
-void tmo_reinhard02(unsigned int width, unsigned int height, 
-  const float *Y, float *L, 
+void tmo_reinhard02(
+  const pfstmo::Array2D *Y, pfstmo::Array2D *L, 
   bool use_scales, float key, float phi, 
-  int num, int low, int high, bool temporal_coherent );
+  int num, int low, int high, bool temporal_coherent, float border = 0.f);
 
 #endif /* _tmo_reinhard02_h_ */
