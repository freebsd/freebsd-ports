--- ./plugins/core/qPCL/PclUtils/filters/MLSSmoothingUpsampling.cpp.orig	2019-01-06 17:02:13.000000000 -0500
+++ ./plugins/core/qPCL/PclUtils/filters/MLSSmoothingUpsampling.cpp	2019-01-07 13:52:41.029660000 -0500
@@ -51,7 +51,7 @@
 {
 	typename pcl::search::KdTree<PointInT>::Ptr tree (new pcl::search::KdTree<PointInT>);
 
-#ifdef _OPENMP
+#if 0 && defined(_OPENMP) // disabled: the only place where omp_xx is used directly
 	//create the smoothing object
 	pcl::MovingLeastSquaresOMP< PointInT, PointOutT > smoother;
 	int n_threads = omp_get_max_threads();
