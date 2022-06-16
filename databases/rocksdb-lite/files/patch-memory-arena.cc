--- memory/arena.cc.orig	2021-06-25 21:15:04 UTC
+++ memory/arena.cc
@@ -29,7 +29,7 @@ const size_t Arena::kInlineSize;
 
 const size_t Arena::kMinBlockSize = 4096;
 const size_t Arena::kMaxBlockSize = 2u << 30;
-static const int kAlignUnit = alignof(max_align_t);
+static const int kAlignUnit = alignof(std::max_align_t);
 
 size_t OptimizeBlockSize(size_t block_size) {
   // Make sure block_size is in optimal range
