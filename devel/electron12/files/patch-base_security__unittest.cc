--- base/security_unittest.cc.orig	2021-01-07 00:36:18 UTC
+++ base/security_unittest.cc
@@ -61,7 +61,7 @@ NOINLINE Type HideValueFromCompiler(volatile Type valu
 void OverflowTestsSoftExpectTrue(bool overflow_detected) {
   if (!overflow_detected) {
 #if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || \
-    defined(OS_APPLE)
+    defined(OS_APPLE) || defined(OS_BSD)
     // Sadly, on Linux, Android, and OSX we don't have a good story yet. Don't
     // fail the test, but report.
     printf("Platform has overflow: %s\n",
@@ -123,7 +123,7 @@ TEST(SecurityTest, MAYBE_NewOverflow) {
 #endif  // !defined(OS_WIN) || !defined(ARCH_CPU_64_BITS)
 }
 
-#if (defined(OS_LINUX) || defined(OS_CHROMEOS)) && defined(__x86_64__)
+#if (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)) && defined(__x86_64__)
 // Check if ptr1 and ptr2 are separated by less than size chars.
 bool ArePointersToSameArea(void* ptr1, void* ptr2, size_t size) {
   ptrdiff_t ptr_diff = reinterpret_cast<char*>(std::max(ptr1, ptr2)) -
@@ -177,6 +177,6 @@ TEST(SecurityTest, MALLOC_OVERFLOW_TEST(RandomMemoryAl
   EXPECT_FALSE(impossible_random_address);
 }
 
-#endif  // (defined(OS_LINUX) || defined(OS_CHROMEOS)) && defined(__x86_64__)
+#endif  // (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)) && defined(__x86_64__)
 
 }  // namespace
