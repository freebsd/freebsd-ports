--- ld.cpp.orig	2020-04-15 12:56:27 UTC
+++ ld.cpp
@@ -1004,7 +1004,9 @@ void gcta::calcu_max_ld_rsq_blk(eigenVector &multi_rsq
         }
 
 
-        SelfAdjointEigenSolver<MatrixXf> pca(rsq_sub.array());
+	// Fixed compile by removing .array().  Not sure about the validity
+	// of this change, but it seemed reasonable based on constructor docs.
+        SelfAdjointEigenSolver<MatrixXf> pca(rsq_sub);
 
                 // debug
        // ofstream tmp("tmp_R.txt");
