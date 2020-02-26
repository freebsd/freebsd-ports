https://github.com/KhronosGroup/glslang/commit/24b3e8384e93

In file included from Externals/glslang/glslang/GenericCodeGen/CodeGen.cpp:35:
In file included from Externals/glslang/glslang/GenericCodeGen/../Include/Common.h:107:
Externals/glslang/glslang/GenericCodeGen/../Include/PoolAlloc.h:307:54: error: 'operator=' is a private member of 'glslang::TPoolAllocator'
    void setAllocator(TPoolAllocator* a) { allocator = *a; }
                                           ~~~~~~~~~ ^ ~~
Externals/glslang/glslang/GenericCodeGen/../Include/PoolAlloc.h:244:21: note: declared private here
    TPoolAllocator& operator=(const TPoolAllocator&);  // don't allow assignment operator
                    ^
In file included from Externals/glslang/glslang/GenericCodeGen/CodeGen.cpp:36:
In file included from Externals/glslang/glslang/GenericCodeGen/../Include/ShHandle.h:46:
Externals/glslang/glslang/GenericCodeGen/../Include/../Public/ShaderLang.h:85:22: warning: '__fastcall__' calling convention is not supported for this target [-Wignored-attributes]
SH_IMPORT_EXPORT int __fastcall ShFinalize();
                     ^

--- Externals/glslang/glslang/Include/PoolAlloc.h.orig	2019-10-07 00:46:03 UTC
+++ Externals/glslang/glslang/Include/PoolAlloc.h
@@ -304,7 +304,6 @@ class pool_allocator { (public)
     size_type max_size() const { return static_cast<size_type>(-1) / sizeof(T); }
     size_type max_size(int size) const { return static_cast<size_type>(-1) / size; }
 
-    void setAllocator(TPoolAllocator* a) { allocator = *a; }
     TPoolAllocator& getAllocator() const { return allocator; }
 
 protected:
