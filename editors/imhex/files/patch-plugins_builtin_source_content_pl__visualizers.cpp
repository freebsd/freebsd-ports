--- plugins/builtin/source/content/pl_visualizers.cpp.orig	2023-06-24 10:07:39 UTC
+++ plugins/builtin/source/content/pl_visualizers.cpp
@@ -307,11 +307,11 @@ namespace hex::plugin::builtin {
 
                 ImGui::TableNextColumn();
                 ImGui::TextUnformatted("hex.builtin.pl_visualizer.3d.rotation"_lang);
-                ImGui::VSliderFloat("##X", ImVec2(18_scaled, textureSize.y), &rotation.data()[0], 0, std::numbers::pi * 2, "", ImGuiSliderFlags_AlwaysClamp);
+                ImGui::VSliderFloat("##X", ImVec2(18_scaled, textureSize.y), &rotation.data()[0], 0, 3.141592653589793238462643383279502884L * 2, "", ImGuiSliderFlags_AlwaysClamp);
                 ImGui::SameLine();
-                ImGui::VSliderFloat("##Y", ImVec2(18_scaled, textureSize.y), &rotation.data()[1], 0, std::numbers::pi * 2, "", ImGuiSliderFlags_AlwaysClamp);
+                ImGui::VSliderFloat("##Y", ImVec2(18_scaled, textureSize.y), &rotation.data()[1], 0, 3.141592653589793238462643383279502884L * 2, "", ImGuiSliderFlags_AlwaysClamp);
                 ImGui::SameLine();
-                ImGui::VSliderFloat("##Z", ImVec2(18_scaled, textureSize.y), &rotation.data()[2], 0, std::numbers::pi * 2, "", ImGuiSliderFlags_AlwaysClamp);
+                ImGui::VSliderFloat("##Z", ImVec2(18_scaled, textureSize.y), &rotation.data()[2], 0, 3.141592653589793238462643383279502884L * 2, "", ImGuiSliderFlags_AlwaysClamp);
 
                 ImGui::TableNextRow();
                 ImGui::TableNextColumn();
@@ -323,10 +323,10 @@ namespace hex::plugin::builtin {
                 ImGui::PopItemWidth();
 
                 for (u8 i = 0; i < 3; i++) {
-                    while (rotation.data()[i] > std::numbers::pi * 2)
-                        rotation.data()[i] -= std::numbers::pi * 2;
+                    while (rotation.data()[i] > 3.141592653589793238462643383279502884L * 2)
+                        rotation.data()[i] -= 3.141592653589793238462643383279502884L * 2;
                     while (rotation.data()[i] < 0)
-                        rotation.data()[i] += std::numbers::pi * 2;
+                        rotation.data()[i] += 3.141592653589793238462643383279502884L * 2;
                 }
 
                 ImGui::TableNextColumn();
