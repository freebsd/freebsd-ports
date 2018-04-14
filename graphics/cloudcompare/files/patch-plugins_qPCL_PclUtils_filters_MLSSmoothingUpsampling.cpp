--- plugins/qPCL/PclUtils/filters/MLSSmoothingUpsampling.cpp.orig	2018-04-14 06:09:41 UTC
+++ plugins/qPCL/PclUtils/filters/MLSSmoothingUpsampling.cpp
@@ -51,7 +51,7 @@ int smooth_mls(const typename pcl::Point
 {
 	typename pcl::search::KdTree<PointInT>::Ptr tree (new pcl::search::KdTree<PointInT>);
 
-#ifdef _OPENMP
+#if 0 && defined(_OPENMP) // disabled: the only place where omp_xx is used directly
 	//create the smoothing object
 	pcl::MovingLeastSquaresOMP< PointInT, PointOutT > smoother;
 	int n_threads = omp_get_max_threads();
