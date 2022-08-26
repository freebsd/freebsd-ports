--- plugins/builtin/source/content/views/view_pattern_editor.cpp.orig	2022-08-20 15:52:06 UTC
+++ plugins/builtin/source/content/views/view_pattern_editor.cpp
@@ -741,7 +741,7 @@ namespace hex::plugin::builtin {
                     ImGui::TableNextColumn();
                     ImGui::TextFormatted("{}", pattern->getEndian() == std::endian::little ? "hex.builtin.common.little"_lang : "hex.builtin.common.big"_lang);
 
-                    if (const auto &comment = pattern->getComment(); comment.has_value()) {
+                    if (const auto &comment = pattern->getComment(); comment != nullptr) {
                         ImGui::TableNextRow();
                         ImGui::TableNextColumn();
                         ImGui::TextFormatted("{}: ", "hex.builtin.common.comment"_lang);
