--- src/rollback.cpp.orig	2023-05-01 20:59:36 UTC
+++ src/rollback.cpp
@@ -309,7 +309,7 @@ void btrfs::read_chunks() {
 
         auto& ci = *(CHUNK_ITEM*)(ptr + sizeof(key));
 
-        basic_string_view<uint8_t> chunk_item{ptr + sizeof(key), sizeof(ci) + (ci.num_stripes * sizeof(CHUNK_ITEM_STRIPE))};
+        basic_string_view<char8_t> chunk_item{reinterpret_cast<const char8_t*>(ptr) + sizeof(key), sizeof(ci) + (ci.num_stripes * sizeof(CHUNK_ITEM_STRIPE))};
 
         chunks.emplace(key.offset, buffer_t{chunk_item.data(), chunk_item.data() + chunk_item.size()});
 
