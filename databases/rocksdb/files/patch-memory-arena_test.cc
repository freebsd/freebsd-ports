--- memory/arena_test.cc.orig	2023-02-19 21:44:55 UTC
+++ memory/arena_test.cc
@@ -96,7 +96,7 @@ static void ApproximateMemoryUsageTest(size_t huge_pag
   ASSERT_EQ(kZero, arena.ApproximateMemoryUsage());
 
   // allocate inline bytes
-  const size_t kAlignUnit = alignof(max_align_t);
+  const size_t kAlignUnit = alignof(std::max_align_t);
   EXPECT_TRUE(arena.IsInInlineBlock());
   arena.AllocateAligned(kAlignUnit);
   EXPECT_TRUE(arena.IsInInlineBlock());
