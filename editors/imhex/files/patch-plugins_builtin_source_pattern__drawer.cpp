--- plugins/builtin/source/pattern_drawer.cpp.orig	2022-08-20 15:51:56 UTC
+++ plugins/builtin/source/pattern_drawer.cpp
@@ -277,7 +277,7 @@ namespace hex {
 
 
     void PatternDrawer::drawCommentTooltip(const pl::ptrn::Pattern &pattern) const {
-        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenBlockedByActiveItem) && pattern.getComment().has_value()) {
+        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenBlockedByActiveItem) && pattern.getComment() != nullptr) {
             ImGui::BeginTooltip();
             ImGui::TextUnformatted(pattern.getComment()->c_str());
             ImGui::EndTooltip();
