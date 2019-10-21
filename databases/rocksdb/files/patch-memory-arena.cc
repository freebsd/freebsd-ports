--- memory/arena.cc.orig	2018-01-31 01:15:39 UTC
+++ memory/arena.cc
@@ -33,7 +33,7 @@ const size_t Arena::kInlineSize;
 
 const size_t Arena::kMinBlockSize = 4096;
 const size_t Arena::kMaxBlockSize = 2u << 30;
-static const int kAlignUnit = alignof(max_align_t);
+static const int kAlignUnit = alignof(std::max_align_t);
 
 size_t OptimizeBlockSize(size_t block_size) {
   // Make sure block_size is in optimal range
