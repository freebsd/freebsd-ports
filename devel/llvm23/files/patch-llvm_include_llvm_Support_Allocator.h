--- llvm/include/llvm/Support/Allocator.h.orig
+++ llvm/include/llvm/Support/Allocator.h
@@ -64,7 +64,11 @@
 /// CurPtr when the requested alignment is no greater than MinAlign.
 template <typename AllocatorT = MallocAllocator, size_t SlabSize = 4096,
           size_t SizeThreshold = SlabSize, size_t GrowthDelay = 128,
+#ifdef __ILP32__
+          size_t MinAlign = 4>
+#else
           size_t MinAlign = 8>
+#endif
 class BumpPtrAllocatorImpl
     : public AllocatorBase<BumpPtrAllocatorImpl<
           AllocatorT, SlabSize, SizeThreshold, GrowthDelay, MinAlign>>,
