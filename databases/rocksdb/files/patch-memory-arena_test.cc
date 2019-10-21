--- memory/arena_test.cc.orig	2018-01-31 01:15:39 UTC
+++ memory/arena_test.cc
@@ -91,7 +91,7 @@ static void ApproximateMemoryUsageTest(s
   ASSERT_EQ(kZero, arena.ApproximateMemoryUsage());
 
   // allocate inline bytes
-  const size_t kAlignUnit = alignof(max_align_t);
+  const size_t kAlignUnit = alignof(std::max_align_t);
   EXPECT_TRUE(arena.IsInInlineBlock());
   arena.AllocateAligned(kAlignUnit);
   EXPECT_TRUE(arena.IsInInlineBlock());
