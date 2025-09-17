--- plugins/input/tiles/pmtiles_source.hpp.orig	2025-09-17 23:55:13 UTC
+++ plugins/input/tiles/pmtiles_source.hpp
@@ -511,7 +511,7 @@ class pmtiles_source : public tiles_source
         }
         else
         {
-            metadata = {data() + metadata_offset, metadata_length};
+            metadata = {data() + metadata_offset, static_cast<size_t>(metadata_length)};
         }
         boost::json::value json_value;
         try
