--- plugins/input/tiles/pmtiles_source.hpp.orig	2025-10-05 04:06:02 UTC
+++ plugins/input/tiles/pmtiles_source.hpp
@@ -470,7 +470,7 @@ class pmtiles_source : public tiles_source,
             {
                 std::string decompressed_dir;
 #if defined(MAPNIK_MEMORY_MAPPED_FILE)
-                std::string_view buffer{file_.buffer().first + dir_offset, dir_length};
+                std::string_view buffer{file_.buffer().first + dir_offset, static_cast<std::size_t>(dir_length)};
 #else
                 std::string buffer;
                 buffer.resize(dir_length);
@@ -559,7 +559,7 @@ class pmtiles_source : public tiles_source,
     {
         std::string metadata;
 #if defined(MAPNIK_MEMORY_MAPPED_FILE)
-        std::string_view buffer{file_.buffer().first + metadata_offset_, metadata_length_};
+        std::string_view buffer{file_.buffer().first + metadata_offset_, static_cast<std::size_t>(metadata_length_)};
 #else
         std::string buffer;
         buffer.resize(metadata_length_);
