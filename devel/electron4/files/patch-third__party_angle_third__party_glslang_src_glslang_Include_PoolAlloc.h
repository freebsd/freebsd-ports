--- third_party/angle/third_party/glslang/src/glslang/Include/PoolAlloc.h.orig	2020-03-14 11:01:09 UTC
+++ third_party/angle/third_party/glslang/src/glslang/Include/PoolAlloc.h
@@ -304,7 +304,6 @@ class pool_allocator { (public)
     size_type max_size() const { return static_cast<size_type>(-1) / sizeof(T); }
     size_type max_size(int size) const { return static_cast<size_type>(-1) / size; }
 
-    void setAllocator(TPoolAllocator* a) { allocator = *a; }
     TPoolAllocator& getAllocator() const { return allocator; }
 
 protected:
