--- plugins/builtin/source/content/views/view_hex_editor.cpp.orig	2022-10-12 10:48:50 UTC
+++ plugins/builtin/source/content/views/view_hex_editor.cpp
@@ -290,7 +290,7 @@ namespace hex::plugin::builtin {
             reader.seek(this->m_searchPosition.value_or(0x00));
 
             constexpr static auto searchFunction = [](const auto &haystackBegin, const auto &haystackEnd, const auto &needleBegin, const auto &needleEnd) {
-                return std::search(haystackBegin, haystackEnd, std::boyer_moore_horspool_searcher(needleBegin, needleEnd));
+                return std::search(haystackBegin, haystackEnd, needleBegin, needleEnd);
             };
 
             if (!backwards) {
