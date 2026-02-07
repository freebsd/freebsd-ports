--- src/slic3r/GUI/PresetComboBoxes.cpp.orig	2024-12-20 11:54:34 UTC
+++ src/slic3r/GUI/PresetComboBoxes.cpp
@@ -890,7 +890,7 @@ void PlaterPresetComboBox::show_edit_menu()
         [this](wxCommandEvent&) { this->switch_to_tab(); }, "cog", menu, []() { return true; }, wxGetApp().plater());
 
     if (m_type == Preset::TYPE_FILAMENT) {
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
         // To edit extruder color from the sidebar
         append_menu_item(menu, wxID_ANY, _L("Change extruder color"), "",
             [this](wxCommandEvent&) { this->change_extruder_color(); }, "funnel", menu, []() { return true; }, wxGetApp().plater());
