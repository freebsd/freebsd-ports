--- storage/innobase/include/log0parsed_index_lru_cache.h.orig	2026-10-30 11:03:27 UTC
+++ storage/innobase/include/log0parsed_index_lru_cache.h
@@ -40,8 +40,9 @@
   and one for each of srv_n_read_io_threads. */
   static constexpr size_t k_capacity = 100;
 
-  using sequence = std::basic_string<byte>;
-  using sequence_view = std::basic_string_view<byte>;
+  using traits = ut::byte_traits<byte>;
+  using sequence = std::basic_string<byte, traits>;
+  using sequence_view = std::basic_string_view<byte, traits>;
 
   Parsed_index_lru_cache() : m_cache(k_capacity) {}
   Parsed_index_lru_cache(const Parsed_index_lru_cache &) = delete;
