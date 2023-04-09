--- plugins/builtin/source/ui/pattern_drawer.cpp.orig	2023-04-04 10:04:22 UTC
+++ plugins/builtin/source/ui/pattern_drawer.cpp
@@ -155,7 +155,8 @@ namespace hex::plugin::builtin::ui {
                 ImGui::TextUnformatted("hex.builtin.pattern_drawer.visualizer.invalid_parameter_count"_lang);
             } else {
                 try {
-                    visualizer.callback(pattern, iteratable, reset, { arguments.begin() + 1, arguments.end() });
+                    const std::vector<pl::core::Token::Literal> args = { arguments.begin() + 1, arguments.end() };
+                    visualizer.callback(pattern, iteratable, reset, args);
                 } catch (std::exception &e) {
                     this->m_lastVisualizerError = e.what();
                 }
