--- intern/libmv/libmv/tracking/track_region.cc.orig	2026-02-09 05:15:57 UTC
+++ intern/libmv/libmv/tracking/track_region.cc
@@ -940,7 +940,11 @@ struct AffineWarp {
     }
 
     // TODO(keir): Check solution quality.
+#if EIGEN_VERSION_AT_LEAST(3, 4, 0)
+    Vec4 a = Q1.jacobiSvd(Eigen::ComputeThinU | Eigen::ComputeThinV).solve(Q2);
+#else
     Vec4 a = Q1.jacobiSvd<Eigen::ComputeThinU | Eigen::ComputeThinV>().solve(Q2);
+#endif
     parameters[2] = a[0];
     parameters[3] = a[1];
     parameters[4] = a[2];
