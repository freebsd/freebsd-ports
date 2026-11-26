--- dec_stream.cc.orig	2026-01-14 20:55:17 UTC
+++ dec_stream.cc
@@ -424,7 +424,15 @@ extern "C" void * dsplitter( void * arg )
   const int buffer_size = max_packet_size;
   // buffer with room for trailer, header, data, and sentinel "LZIP"
   const int base_buffer_size = tsize + hsize + buffer_size + 4;
-  uint8_t * const base_buffer = new( std::nothrow ) uint8_t[base_buffer_size];
+  // FreeBSD: temporary workaround for a clang miscompilation (seen with
+  // clang 19 and 20).  With a const pointer and a constant size, clang
+  // folds '!base_buffer' to true when base_buffer_size exceeds its
+  // -fconstexpr-steps limit (default 2^20), so the splitter always
+  // reports "Not enough memory." and stdin is never read.  Raising
+  // -fconstexpr-steps would also work, but it depends on the compiler
+  // and on the buffer size staying under whatever value we choose;
+  // dropping 'const' avoids the folding.  Remove once clang is fixed.
+  uint8_t * base_buffer = new( std::nothrow ) uint8_t[base_buffer_size];
   if( !base_buffer )
     {
 mem_fail:
