--- plugins/builtin/source/content/views/view_pattern_editor.cpp.orig	2023-04-04 10:04:22 UTC
+++ plugins/builtin/source/content/views/view_pattern_editor.cpp
@@ -440,9 +440,9 @@ namespace hex::plugin::builtin {
                     dataProvider->writeRaw(0x00, section.data.data(), section.data.size());
                     dataProvider->setReadOnly(true);
 
-                    auto hexEditor = auto(this->m_sectionHexEditor);
+                    auto hexEditor = this->m_sectionHexEditor;
 
-                    hexEditor.setBackgroundHighlightCallback([this, id](u64 address, const u8 *, size_t) -> std::optional<color_t> {
+                    hexEditor.setBackgroundHighlightCallback([this, id=id](u64 address, const u8 *, size_t) -> std::optional<color_t> {
                         if (this->m_runningEvaluators != 0)
                             return std::nullopt;
                         if (!ImHexApi::Provider::isValid())
@@ -465,7 +465,7 @@ namespace hex::plugin::builtin {
                     auto patternProvider = ImHexApi::Provider::get();
 
 
-                    this->m_sectionWindowDrawer[patternProvider] = [id, patternProvider, dataProvider = std::move(dataProvider), hexEditor = std::move(hexEditor), patternDrawer = ui::PatternDrawer()] mutable {
+                    this->m_sectionWindowDrawer[patternProvider] = [id=id, patternProvider, dataProvider = std::move(dataProvider), hexEditor = std::move(hexEditor), patternDrawer = ui::PatternDrawer()] mutable {
                         hexEditor.setProvider(dataProvider.get());
                         hexEditor.draw(480_scaled);
                         patternDrawer.setSelectionCallback([&](const auto &region) {
@@ -952,7 +952,7 @@ namespace hex::plugin::builtin {
                                                                if (type->isTemplateType())
                                                                    continue;
 
-                                                               createNestedMenu(hex::splitString(typeName, "::"), [&] {
+                                                               createNestedMenu(hex::splitString(typeName, "::"), [&, typeName=typeName] {
                                                                    std::string variableName;
                                                                    for (char &c : hex::replaceStrings(typeName, "::", "_"))
                                                                        variableName += static_cast<char>(std::tolower(c));
