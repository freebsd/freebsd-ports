--- tiledb/sm/fragment/fragment_metadata.cc.orig	2023-04-26 01:28:54 UTC
+++ tiledb/sm/fragment/fragment_metadata.cc
@@ -1718,11 +1718,11 @@ std::string_view FragmentMetadata::get_tile_min_as<std
                     tile_min_var_buffer_[idx].size() - min_offset :
                     offsets[tile_idx + 1] - min_offset;
     char* min = &tile_min_var_buffer_[idx][min_offset];
-    return {min, size};
+    return {min, (std::size_t) size};
   } else {
     auto size = array_schema_->cell_size(name);
     void* min = &tile_min_buffer_[idx][tile_idx * size];
-    return {static_cast<char*>(min), size};
+    return {static_cast<char*>(min), (std::size_t) size};
   }
 }
 
@@ -1791,11 +1791,11 @@ std::string_view FragmentMetadata::get_tile_max_as<std
                     tile_max_var_buffer_[idx].size() - max_offset :
                     offsets[tile_idx + 1] - max_offset;
     char* max = &tile_max_var_buffer_[idx][max_offset];
-    return {max, size};
+    return {max, (std::size_t) size};
   } else {
     auto size = array_schema_->cell_size(name);
     void* max = &tile_max_buffer_[idx][tile_idx * size];
-    return {static_cast<char*>(max), size};
+    return {static_cast<char*>(max), (std::size_t) size};
   }
 }
 
