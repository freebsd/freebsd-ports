--- base/process/memory_unittest.cc.orig	2019-09-10 11:13:31 UTC
+++ base/process/memory_unittest.cc
@@ -104,7 +104,7 @@ TEST(MemoryTest, AllocatorShimWorking) {
 // OpenBSD does not support these tests. Don't test these on ASan/TSan/MSan
 // configurations: only test the real allocator.
 // Windows only supports these tests with the allocator shim in place.
-#if !defined(OS_OPENBSD) && BUILDFLAG(USE_ALLOCATOR_SHIM) && \
+#if !defined(OS_BSD) && BUILDFLAG(USE_ALLOCATOR_SHIM) && \
     !defined(MEMORY_TOOL_REPLACES_ALLOCATOR)
 
 namespace {
@@ -529,5 +529,5 @@ TEST_F(OutOfMemoryHandledTest, UncheckedCalloc) {
   EXPECT_FALSE(base::UncheckedCalloc(1, test_size_, &value_));
   EXPECT_TRUE(value_ == nullptr);
 }
-#endif  // !defined(OS_OPENBSD) && BUILDFLAG(ENABLE_WIN_ALLOCATOR_SHIM_TESTS) &&
+#endif  // !defined(OS_BSD) && BUILDFLAG(ENABLE_WIN_ALLOCATOR_SHIM_TESTS) &&
         // !defined(MEMORY_TOOL_REPLACES_ALLOCATOR)
