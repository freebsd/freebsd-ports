-- FreeBSD's libc++ implementation retains/releases the object extra times when
-- looking up a RetainPtr in a std::set, so use the sanitizer-style expected
-- counts on this platform.
--- core/fxcrt/retain_ptr_unittest.cpp.orig	2026-09-24 10:57:02 UTC
+++ core/fxcrt/retain_ptr_unittest.cpp
@@ -495,8 +495,8 @@ TEST(RetainPtr, SetContains) {
   EXPECT_TRUE(pdfium::Contains(the_set, ptr1));
   EXPECT_FALSE(pdfium::Contains(the_set, ptr2));
 #if !BUILDFLAG(IS_WIN) &&                                       \
-    (defined(ADDRESS_SANITIZER) || defined(MEMORY_SANITIZER) || \
-     defined(UNDEFINED_SANITIZER))
+    (BUILDFLAG(IS_BSD) || defined(ADDRESS_SANITIZER) ||          \
+     defined(MEMORY_SANITIZER) || defined(UNDEFINED_SANITIZER))
   constexpr int kExpectedObj2RetainCount = 4;
   constexpr int kExpectedObj2ReleaseCount = 2;
 #else
