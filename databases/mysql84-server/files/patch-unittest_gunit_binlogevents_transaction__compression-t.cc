--- unittest/gunit/binlogevents/transaction_compression-t.cc.orig	2024-07-12 19:20:22 UTC
+++ unittest/gunit/binlogevents/transaction_compression-t.cc
@@ -49,7 +49,7 @@ class TransactionPayloadCompressionTest : public ::tes
   using Managed_buffer_t = Decompressor_t::Managed_buffer_t;
   using Size_t = Decompressor_t::Size_t;
   using Char_t = Decompressor_t::Char_t;
-  using String_t = std::basic_string<Char_t>;
+  using String_t = std::vector<Char_t>;
   using Decompress_status_t =
       mysql::binlog::event::compression::Decompress_status;
   using Compress_status_t = mysql::binlog::event::compression::Compress_status;
