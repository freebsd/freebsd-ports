--- plugins/builtin/source/content/views/view_pattern_editor.cpp.orig	2023-06-24 10:07:39 UTC
+++ plugins/builtin/source/content/views/view_pattern_editor.cpp
@@ -494,9 +494,9 @@ namespace hex::plugin::builtin {
                         dataProvider->writeRaw(0x00, section.data.data(), section.data.size());
                         dataProvider->setReadOnly(true);
 
-                        auto hexEditor = auto(this->m_sectionHexEditor);
+                        auto hexEditor = this->m_sectionHexEditor;
 
-                        hexEditor.setBackgroundHighlightCallback([this, id, &runtime](u64 address, const u8 *, size_t) -> std::optional<color_t> {
+                        hexEditor.setBackgroundHighlightCallback([this, id=id, &runtime](u64 address, const u8 *, size_t) -> std::optional<color_t> {
                             if (this->m_runningEvaluators != 0)
                                 return std::nullopt;
                             if (!ImHexApi::Provider::isValid())
@@ -519,7 +519,7 @@ namespace hex::plugin::builtin {
                         auto patternProvider = ImHexApi::Provider::get();
 
 
-                        this->m_sectionWindowDrawer[patternProvider] = [this, id, patternProvider, dataProvider = std::move(dataProvider), hexEditor, patternDrawer = ui::PatternDrawer(), &runtime] mutable {
+                        this->m_sectionWindowDrawer[patternProvider] = [this, id=id, patternProvider, dataProvider = std::move(dataProvider), hexEditor, patternDrawer = ui::PatternDrawer(), &runtime] mutable {
                             hexEditor.setProvider(dataProvider.get());
                             hexEditor.draw(480_scaled);
                             patternDrawer.setSelectionCallback([&](const auto &region) {
@@ -1138,7 +1138,7 @@ namespace hex::plugin::builtin {
                                                                if (type->isTemplateType())
                                                                    continue;
 
-                                                               createNestedMenu(hex::splitString(typeName, "::"), [&, this] {
+                                                               createNestedMenu(hex::splitString(typeName, "::"), [&, this, typeName=typeName] {
                                                                    std::string variableName;
                                                                    for (char &c : hex::replaceStrings(typeName, "::", "_"))
                                                                        variableName += static_cast<char>(std::tolower(c));
