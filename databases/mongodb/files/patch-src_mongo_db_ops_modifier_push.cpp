--- src/mongo/db/ops/modifier_push.cpp.orig	2014-05-15 15:24:21.650184430 +0000
+++ src/mongo/db/ops/modifier_push.cpp	2014-05-15 15:25:51.014179801 +0000
@@ -646,7 +646,7 @@
             }
 
             const int64_t numChildren = mutablebson::countChildren(_preparedState->elemFound);
-            int64_t countRemoved = std::max(static_cast<int64_t>(0), numChildren - abs(_slice));
+            int64_t countRemoved = std::max(static_cast<int64_t>(0), numChildren - (_slice >= 0 ? _slice : -_slice));
 
             // If _slice is negative, remove from the bottom, otherwise from the top
             const bool removeFromEnd = (_slice > 0);
