--- src/rollback.cpp.orig	2026-08-10 17:55:01 UTC
+++ src/rollback.cpp
@@ -324,7 +324,8 @@ void btrfs::read_chunks() {
 
         auto& ci = *(btrfs_chunk*)(ptr + sizeof(key));
 
-        basic_string_view<uint8_t> chunk_item{ptr + sizeof(key), offsetof(btrfs_chunk, stripe) + (ci.num_stripes * sizeof(btrfs_stripe))};
+        basic_string_view<char8_t> chunk_item{reinterpret_cast<const char8_t*>(ptr) + sizeof(key),
+            offsetof(btrfs_chunk, stripe) + ci.num_stripes * sizeof(btrfs_stripe)};
 
         chunks.emplace(+key.offset, buffer_t{chunk_item.data(), chunk_item.data() + chunk_item.size()});
 
