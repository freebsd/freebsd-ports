--- include/phasar/Utils/ArraySet.h.orig
+++ include/phasar/Utils/ArraySet.h
@@ -89,7 +89,7 @@
 
 private:
   static bool isContained(llvm::ArrayRef<T> Data, ByConstRef<T> Val) noexcept {
-    auto It = std::find(std::execution::unseq, Data.begin(), Data.end(), Val);
+    auto It = std::find(Data.begin(), Data.end(), Val);
     return It != Data.end();
   }
 
