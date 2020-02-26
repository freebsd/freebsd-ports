https://github.com/KhronosGroup/glslang/commit/24b3e8384e93

In file included from MachineIndependent/glslang.y:60:
In file included from glslang/glslang/MachineIndependent/SymbolTable.h:68:
In file included from glslang/glslang/MachineIndependent/../Include/Common.h:107:
glslang/glslang/MachineIndependent/../Include/PoolAlloc.h:307:54: error: 'operator=' is a private member of 'glslang::TPoolAllocator'
    void setAllocator(TPoolAllocator* a) { allocator = *a; }
                                           ~~~~~~~~~ ^ ~~
glslang/glslang/MachineIndependent/../Include/PoolAlloc.h:244:21: note: declared private here
    TPoolAllocator& operator=(const TPoolAllocator&);  // don't allow assignment operator
                    ^

--- glslang/glslang/Include/PoolAlloc.h.orig	2019-05-04 19:58:35 UTC
+++ glslang/glslang/Include/PoolAlloc.h
@@ -304,7 +304,6 @@ class pool_allocator { (public)
     size_type max_size() const { return static_cast<size_type>(-1) / sizeof(T); }
     size_type max_size(int size) const { return static_cast<size_type>(-1) / size; }
 
-    void setAllocator(TPoolAllocator* a) { allocator = *a; }
     TPoolAllocator& getAllocator() const { return allocator; }
 
 protected:
