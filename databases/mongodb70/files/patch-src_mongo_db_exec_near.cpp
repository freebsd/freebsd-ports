--- src/mongo/db/exec/near.cpp.orig	2023-06-15 22:07:57 UTC
+++ src/mongo/db/exec/near.cpp
@@ -42,6 +42,21 @@ using std::vector;
 using std::unique_ptr;
 using std::vector;
 
+/**
+ * Holds a generic search result with a distance computed in some fashion.
+ */
+struct NearStage::SearchResult {
+    SearchResult(WorkingSetID resultID, double distance) : resultID(resultID), distance(distance) {}
+
+    bool operator<(const SearchResult& other) const {
+        // We want increasing distance, not decreasing, so we reverse the <
+        return distance > other.distance;
+    }
+
+    WorkingSetID resultID;
+    double distance;
+};
+
 NearStage::NearStage(ExpressionContext* expCtx,
                      const char* typeName,
                      StageType type,
@@ -113,21 +128,6 @@ PlanStage::StageState NearStage::doWork(WorkingSetID* 
 
     return nextState;
 }
-
-/**
- * Holds a generic search result with a distance computed in some fashion.
- */
-struct NearStage::SearchResult {
-    SearchResult(WorkingSetID resultID, double distance) : resultID(resultID), distance(distance) {}
-
-    bool operator<(const SearchResult& other) const {
-        // We want increasing distance, not decreasing, so we reverse the <
-        return distance > other.distance;
-    }
-
-    WorkingSetID resultID;
-    double distance;
-};
 
 // Set "toReturn" when NEED_YIELD.
 PlanStage::StageState NearStage::bufferNext(WorkingSetID* toReturn) {
