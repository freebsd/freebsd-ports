--- src/mongo/db/kill_current_op.cpp.orig	2014-05-15 15:30:33.100157820 +0000
+++ src/mongo/db/kill_current_op.cpp	2014-05-15 15:35:12.714138934 +0000
@@ -152,7 +152,7 @@
         }
 
         // Return true with (approx) probability p = "chance".  Recall: 0 <= chance <= 1.
-        double next = static_cast<double>(std::abs(checkForInterruptPRNG.nextInt64()));
+        double next = std::abs(static_cast<double>(checkForInterruptPRNG.nextInt64()));
         double upperBound =
             std::numeric_limits<int64_t>::max() * failPointInfo["chance"].numberDouble();
         if (next > upperBound) {
