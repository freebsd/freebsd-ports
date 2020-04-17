https://github.com/KhronosGroup/glslang/issues/1869

--- deps/glslang/glslang/glslang/Include/PoolAlloc.h.orig	2020-03-21 22:21:53 UTC
+++ deps/glslang/glslang/glslang/Include/PoolAlloc.h
@@ -304,7 +304,6 @@ class pool_allocator { (public)
     size_type max_size() const { return static_cast<size_type>(-1) / sizeof(T); }
     size_type max_size(int size) const { return static_cast<size_type>(-1) / size; }
 
-    void setAllocator(TPoolAllocator* a) { allocator = *a; }
     TPoolAllocator& getAllocator() const { return allocator; }
 
 protected:
