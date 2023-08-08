--- plugins/builtin/source/content/views/view_find.cpp.orig	2023-06-24 10:07:39 UTC
+++ plugins/builtin/source/content/views/view_find.cpp
@@ -265,7 +265,7 @@ namespace hex::plugin::builtin {
         while (true) {
             task.update(progress);
 
-            occurrence = std::search(reader.begin(), reader.end(), std::boyer_moore_horspool_searcher(bytes.begin(), bytes.end()));
+            occurrence = std::search(reader.begin(), reader.end(), bytes.begin(), bytes.end());
             if (occurrence == reader.end())
                 break;
 
@@ -391,7 +391,7 @@ namespace hex::plugin::builtin {
         for (u64 address = searchRegion.getStartAddress(); address < searchRegion.getEndAddress(); address += advance) {
             task.update(address);
 
-            auto result = std::visit([&](auto tag) {
+            auto result = std::visit([&, min=min, max=max](auto tag) {
                 using T = std::remove_cvref_t<std::decay_t<decltype(tag)>>;
 
                 auto minValue = std::get<T>(min);
