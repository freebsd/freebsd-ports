--- plugins/builtin/source/content/views/view_find.cpp.orig	2022-08-05 19:36:42 UTC
+++ plugins/builtin/source/content/views/view_find.cpp
@@ -247,7 +247,7 @@ namespace hex::plugin::builtin {
         auto sequence = hex::decodeByteString(settings.sequence);
         auto occurrence = reader.begin();
         while (true) {
-            occurrence = std::search(reader.begin(), reader.end(), std::boyer_moore_horspool_searcher(sequence.begin(), sequence.end()));
+            occurrence = std::search(reader.begin(), reader.end(), sequence.begin(), sequence.end());
             if (occurrence == reader.end())
                 break;
 
