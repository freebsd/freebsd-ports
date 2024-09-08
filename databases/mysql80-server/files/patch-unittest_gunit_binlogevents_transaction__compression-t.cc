--- unittest/gunit/binlogevents/transaction_compression-t.cc.orig	2024-07-12 19:15:25 UTC
+++ unittest/gunit/binlogevents/transaction_compression-t.cc
@@ -51,7 +51,7 @@ class TransactionPayloadCompressionTest : public ::tes
   using Managed_buffer_t = Decompressor_t::Managed_buffer_t;
   using Size_t = Decompressor_t::Size_t;
   using Char_t = Decompressor_t::Char_t;
-  using String_t = std::basic_string<Char_t>;
+  using String_t = std::vector<Char_t>;
   using Decompress_status_t =
       binary_log::transaction::compression::Decompress_status;
   using Compress_status_t =
