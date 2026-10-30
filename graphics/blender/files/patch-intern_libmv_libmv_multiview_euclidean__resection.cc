--- intern/libmv/libmv/multiview/euclidean_resection.cc.orig	2026-02-09 05:15:57 UTC
+++ intern/libmv/libmv/multiview/euclidean_resection.cc
@@ -107,7 +107,11 @@ void AbsoluteOrientation(const Mat3X& X, const Mat3X& 
 
   // Find the unit quaternion q that maximizes qNq. It is the eigenvector
   // corresponding to the lagest eigenvalue.
+#if EIGEN_VERSION_AT_LEAST(3, 4, 0)
+  Vec4 q = N.jacobiSvd(Eigen::ComputeFullU).matrixU().col(0);
+#else
   Vec4 q = N.jacobiSvd<Eigen::ComputeFullU>().matrixU().col(0);
+#endif
 
   // Retrieve the 3x3 rotation matrix.
   Vec4 qq = q.array() * q.array();
@@ -246,8 +250,13 @@ void EuclideanResectionAnsarDaniilidis(const Mat2X& x_
   }
 
   int num_lambda = num_points + 1;  // Dimension of the null space of M.
+#if EIGEN_VERSION_AT_LEAST(3, 4, 0)
+  Mat V = M.jacobiSvd(Eigen::ComputeFullV).matrixV().block(
+      0, num_m_rows, num_m_columns, num_lambda);
+#else
   Mat V = M.jacobiSvd<Eigen::ComputeFullV>().matrixV().block(
       0, num_m_rows, num_m_columns, num_lambda);
+#endif
 
   // TODO(vess): The number of constraint equations in K (num_k_rows) must be
   // (num_points + 1) * (num_points + 2)/2. This creates a performance issue
@@ -302,8 +311,13 @@ void EuclideanResectionAnsarDaniilidis(const Mat2X& x_
       ++counter_k_row;
     }
   }
+#if EIGEN_VERSION_AT_LEAST(3, 4, 0)
   Vec L_sq =
+      K.jacobiSvd(Eigen::ComputeFullV).matrixV().col(num_k_columns - 1);
+#else
+  Vec L_sq =
       K.jacobiSvd<Eigen::ComputeFullV>().matrixV().col(num_k_columns - 1);
+#endif
 
   // Pivot on the largest element for numerical stability. Afterwards recover
   // the sign of the lambda solution.
