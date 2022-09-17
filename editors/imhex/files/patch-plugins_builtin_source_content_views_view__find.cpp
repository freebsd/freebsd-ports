--- plugins/builtin/source/content/views/view_find.cpp.orig	2022-09-15 12:40:14 UTC
+++ plugins/builtin/source/content/views/view_find.cpp
@@ -239,7 +239,7 @@ namespace hex::plugin::builtin {
 
         auto occurrence = reader.begin();
         while (true) {
-            occurrence = std::search(reader.begin(), reader.end(), std::boyer_moore_horspool_searcher(sequence.begin(), sequence.end()));
+            occurrence = std::search(reader.begin(), reader.end(), sequence.begin(), sequence.end());
             if (occurrence == reader.end())
                 break;
 
