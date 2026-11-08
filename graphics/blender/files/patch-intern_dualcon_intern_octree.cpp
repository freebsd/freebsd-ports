--- intern/dualcon/intern/octree.cpp.orig	2026-02-09 05:15:57 UTC
+++ intern/dualcon/intern/octree.cpp
@@ -2184,7 +2184,11 @@ static void pseudoInverse(const Eigen::Matrix3f &a, Ei
 static void pseudoInverse(const Eigen::Matrix3f &a, Eigen::Matrix3f &result, float tolerance)
 {
   const int Options = Eigen::ComputeFullU | Eigen::ComputeFullV;
+#if EIGEN_VERSION_AT_LEAST(3, 4, 0)
+  auto svd = a.jacobiSvd(Options);
+#else
   Eigen::JacobiSVD<Eigen::Matrix3f, Options> svd = a.jacobiSvd<Options>();
+#endif
 
   result = svd.matrixV() *
            Eigen::Vector3f((svd.singularValues().array().abs() > tolerance)
