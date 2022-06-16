--- memory/arena.h.orig	2018-01-31 01:15:39 UTC
+++ memory/arena.h
@@ -82,7 +82,7 @@ class Arena : public Allocator {
   }
 
  private:
-  char inline_block_[kInlineSize] __attribute__((__aligned__(alignof(max_align_t))));
+  char inline_block_[kInlineSize] __attribute__((__aligned__(alignof(std::max_align_t))));
   // Number of bytes allocated in one block
   const size_t kBlockSize;
   // Array of new[] allocated memory blocks
