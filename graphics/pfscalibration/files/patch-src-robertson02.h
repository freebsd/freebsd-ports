--- src/robertson02.h.orig	Thu Mar 16 12:22:46 2006
+++ src/robertson02.h	Thu Jun 21 14:34:34 2007
@@ -39,8 +39,9 @@
  * @param I [out] array to put response function
  * @param w weights
  * @param M max camera output (no of discrete steps)
+ * @return number of saturated pixels in the HDR image (0: all OK)
  */
-void robertson02_getResponse( pfs::Array2D* xj, const ExposureList &imgs,
+int robertson02_getResponse( pfs::Array2D* xj, const ExposureList &imgs,
   float* I, const float* w, int M );
 
 
@@ -53,8 +54,9 @@
  * @param I camera response function (array size of M)
  * @param w weighting function for camera output values (array size of M)
  * @param M number of camera output levels
+ * @return number of saturated pixels in the HDR image (0: all OK)
  */
-void robertson02_applyResponse( pfs::Array2D* xj, const ExposureList &imgs, 
+int robertson02_applyResponse( pfs::Array2D* xj, const ExposureList &imgs, 
   const float* I, const float* w, int M );
 
 
