--- llvm/include/llvm/ADT/IntervalMap.h.orig
+++ llvm/include/llvm/ADT/IntervalMap.h
@@ -1042,6 +1042,11 @@
     new(&rootLeaf()) RootLeaf();
   }
 
+  IntervalMap(const IntervalMap &Other) : IntervalMap(Other.allocator) {
+    for (auto i = Other.begin(), e = Other.end(); i != e; ++i)
+      insert(i.start(), i.stop(), i.value());
+  }
+
   ~IntervalMap() {
     clear();
     rootLeaf().~RootLeaf();
