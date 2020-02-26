https://github.com/KhronosGroup/glslang/commit/24b3e8384e93

In file included from libraries/glslang/glslang/GenericCodeGen/CodeGen.cpp:35:
In file included from libraries/glslang/glslang/GenericCodeGen/../Include/Common.h:108:
libraries/glslang/glslang/GenericCodeGen/../Include/PoolAlloc.h:307:54: error: 'operator=' is a private member of 'glslang::TPoolAllocator'
    void setAllocator(TPoolAllocator* a) { allocator = *a; }
                                           ~~~~~~~~~ ^ ~~
libraries/glslang/glslang/GenericCodeGen/../Include/PoolAlloc.h:244:21: note: declared private here
    TPoolAllocator& operator=(const TPoolAllocator&);  // don't allow assignment operator
                    ^

--- src/libraries/glslang/glslang/Include/PoolAlloc.h.orig	2019-10-27 13:44:49 UTC
+++ src/libraries/glslang/glslang/Include/PoolAlloc.h
@@ -304,7 +304,6 @@ class pool_allocator { (public)
     size_type max_size() const { return static_cast<size_type>(-1) / sizeof(T); }
     size_type max_size(int size) const { return static_cast<size_type>(-1) / size; }
 
-    void setAllocator(TPoolAllocator* a) { allocator = *a; }
     TPoolAllocator& getAllocator() const { return allocator; }
 
 protected:
