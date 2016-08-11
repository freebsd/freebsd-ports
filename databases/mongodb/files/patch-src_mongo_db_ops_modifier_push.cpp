--- src/mongo/db/ops/modifier_push.cpp.orig	2016-03-21 17:09:46.000000000 +0100
+++ src/mongo/db/ops/modifier_push.cpp	2016-05-02 12:44:35.408331153 +0200
@@ -646,7 +646,7 @@ namespace mongo {
             }
 
             const int64_t numChildren = mutablebson::countChildren(_preparedState->elemFound);
-            int64_t countRemoved = std::max(static_cast<int64_t>(0), numChildren - abs(_slice));
+            int64_t countRemoved = std::max(static_cast<int64_t>(0), numChildren - (_slice >= 0 ? _slice : -_slice));
 
             // If _slice is negative, remove from the bottom, otherwise from the top
             const bool removeFromEnd = (_slice > 0);
