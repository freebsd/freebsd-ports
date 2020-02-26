https://github.com/KhronosGroup/glslang/commit/24b3e8384e93

In file included from Common/Vulkan/VulkanContext.cpp:28:
In file included from ext/glslang/SPIRV/GlslangToSpv.h:42:
In file included from ext/glslang/SPIRV/SpvTools.h:47:
In file included from ext/glslang/SPIRV/../glslang/MachineIndependent/localintermediate.h:42:
In file included from ext/glslang/SPIRV/../glslang/MachineIndependent/../Include/intermediate.h:55:
In file included from ext/glslang/SPIRV/../glslang/MachineIndependent/../Include/../Include/Common.h:108:
ext/glslang/SPIRV/../glslang/MachineIndependent/../Include/PoolAlloc.h:307:54: error: 'operator=' is a private member of 'glslang::TPoolAllocator'
    void setAllocator(TPoolAllocator* a) { allocator = *a; }
                                           ~~~~~~~~~ ^ ~~
ext/glslang/SPIRV/../glslang/MachineIndependent/../Include/PoolAlloc.h:244:21: note: declared private here
    TPoolAllocator& operator=(const TPoolAllocator&);  // don't allow assignment operator
                    ^

--- ext/glslang/glslang/Include/PoolAlloc.h.orig	2019-06-18 08:00:46 UTC
+++ ext/glslang/glslang/Include/PoolAlloc.h
@@ -304,7 +304,6 @@ class pool_allocator { (public)
     size_type max_size() const { return static_cast<size_type>(-1) / sizeof(T); }
     size_type max_size(int size) const { return static_cast<size_type>(-1) / size; }
 
-    void setAllocator(TPoolAllocator* a) { allocator = *a; }
     TPoolAllocator& getAllocator() const { return allocator; }
 
 protected:
