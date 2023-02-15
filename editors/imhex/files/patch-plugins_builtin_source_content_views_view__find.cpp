--- plugins/builtin/source/content/views/view_find.cpp.orig	2023-02-12 18:24:04 UTC
+++ plugins/builtin/source/content/views/view_find.cpp
@@ -305,7 +305,7 @@ namespace hex::plugin::builtin {
 
         auto occurrence = reader.begin();
         while (true) {
-            occurrence = std::search(reader.begin(), reader.end(), std::boyer_moore_horspool_searcher(bytes.begin(), bytes.end()));
+            occurrence = std::search(reader.begin(), reader.end(), bytes.begin(), bytes.end());
             if (occurrence == reader.end())
                 break;
 
@@ -407,7 +407,7 @@ namespace hex::plugin::builtin {
             if (validBytes == size) {
                 bytes &= hex::bitmask(size * 8);
 
-                auto result = std::visit([&](auto tag) {
+                auto result = std::visit([&, min=min, max=max](auto tag) {
                     using T = std::remove_cvref_t<std::decay_t<decltype(tag)>>;
 
                     auto minValue = std::get<T>(min);
