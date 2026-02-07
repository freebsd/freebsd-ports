--- svm.cpp.orig	2009-04-05 11:40:29 UTC
+++ svm.cpp
@@ -10,6 +10,7 @@
 #include <vector>
 #include <cmath>
 #include <algorithm>
+#include <random>
 #include "feature.h"
 
 namespace zinnia {
@@ -44,10 +45,12 @@ bool svm_train(size_t l,
   }
 
   static const size_t kMaxIteration = 2000;
+  std::random_device device;
+  std::mt19937 engine(device());
   for (size_t iter = 0; iter < kMaxIteration; ++iter) {
     double PGmax_new = -kINF;
     double PGmin_new = kINF;
-    std::random_shuffle(index.begin(), index.begin() + active_size);
+    std::shuffle(index.begin(), index.begin() + active_size, engine);
 
     for (size_t s = 0; s < active_size; ++s) {
       const size_t i = index[s];
