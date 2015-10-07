--- include/llvm/IR/PassManager.h.orig	2015-01-13 23:42:38.000000000 +0100
+++ include/llvm/IR/PassManager.h	2015-08-23 18:33:44.006587000 +0200
@@ -502,7 +502,7 @@ private:
   PreservedAnalyses invalidateImpl(IRUnitT &IR, PreservedAnalyses PA) {
     // Short circuit for a common case of all analyses being preserved.
     if (PA.areAllPreserved())
-      return std::move(PA);
+      return PA;
 
     if (DebugLogging)
       dbgs() << "Invalidating all non-preserved analyses for: "
@@ -542,7 +542,7 @@ private:
     if (ResultsList.empty())
       AnalysisResultLists.erase(&IR);
 
-    return std::move(PA);
+    return PA;
   }
 
   /// \brief List of function analysis pass IDs and associated concept pointers.
