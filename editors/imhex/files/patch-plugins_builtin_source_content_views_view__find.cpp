--- plugins/builtin/source/content/views/view_find.cpp.orig	2023-04-04 10:04:22 UTC
+++ plugins/builtin/source/content/views/view_find.cpp
@@ -314,7 +314,7 @@ namespace hex::plugin::builtin {
         while (true) {
             task.update(progress);
 
-            occurrence = std::search(reader.begin(), reader.end(), std::boyer_moore_horspool_searcher(bytes.begin(), bytes.end()));
+            occurrence = std::search(reader.begin(), reader.end(), bytes.begin(), bytes.end());
             if (occurrence == reader.end())
                 break;
 
@@ -423,7 +423,7 @@ namespace hex::plugin::builtin {
 
                 task.update(address);
 
-                auto result = std::visit([&](auto tag) {
+                auto result = std::visit([&, min=min, max=max](auto tag) {
                     using T = std::remove_cvref_t<std::decay_t<decltype(tag)>>;
 
                     auto minValue = std::get<T>(min);
