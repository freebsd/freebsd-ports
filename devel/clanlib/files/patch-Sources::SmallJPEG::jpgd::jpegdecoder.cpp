--- Sources/SmallJPEG/jpgd/jpegdecoder.cpp.orig	2007-08-09 21:32:35.000000000 +0200
+++ Sources/SmallJPEG/jpgd/jpegdecoder.cpp	2007-08-09 21:35:03.000000000 +0200
@@ -102,7 +102,7 @@
   blocks[i] = q;
 
   // Round to qword boundry, to avoid misaligned accesses with MMX code
-  return ((void *)(((uint)q + 7) & ~7));
+  return ((void *)(((ulong)q + 7) & ~7));
 }
 //------------------------------------------------------------------------------
 // Clear buffer to word values.
@@ -1870,7 +1870,7 @@
   q = (uchar *)alloc(max_blocks_per_row * 64 * sizeof(BLOCK_TYPE) + 8);
 
   // Align to 8-byte boundry, for MMX code
-  q = (uchar *)(((uint)q + 7) & ~7);
+  q = (uchar *)(((ulong)q + 7) & ~7);
 
   // The block_seg[] array's name dates back to the
   // 16-bit assembler implementation. "seg" stood for "segment".
@@ -1880,7 +1880,7 @@
   for (i = 0; i < max_blocks_per_row; i++)
     block_max_zag_set[i] = 64;
 
-  Psample_buf = (uchar *)(((uint)alloc(max_blocks_per_row * 64 + 8) + 7) & ~7);
+  Psample_buf = (uchar *)(((ulong)alloc(max_blocks_per_row * 64 + 8) + 7) & ~7);
 
   total_lines_left = image_y_size;
 
