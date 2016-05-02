--- src/mongo/db/kill_current_op.cpp.orig	2016-03-21 17:09:46.000000000 +0100
+++ src/mongo/db/kill_current_op.cpp	2016-05-02 12:44:35.406331476 +0200
@@ -152,7 +152,7 @@ namespace {
         }
 
         // Return true with (approx) probability p = "chance".  Recall: 0 <= chance <= 1.
-        double next = static_cast<double>(std::abs(checkForInterruptPRNG.nextInt64()));
+        double next = std::abs(static_cast<double>(checkForInterruptPRNG.nextInt64()));
         double upperBound =
             std::numeric_limits<int64_t>::max() * failPointInfo["chance"].numberDouble();
         if (next > upperBound) {
