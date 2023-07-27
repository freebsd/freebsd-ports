--- src/slic3r/GUI/PresetComboBoxes.cpp.orig	2023-07-25 12:38:23 UTC
+++ src/slic3r/GUI/PresetComboBoxes.cpp
@@ -779,7 +779,7 @@ void PlaterPresetComboBox::show_edit_menu()
         [this](wxCommandEvent&) { this->switch_to_tab(); }, "cog", menu, []() { return true; }, wxGetApp().plater());
 
     if (m_type == Preset::TYPE_FILAMENT) {
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
         // To edit extruder color from the sidebar
         append_menu_item(menu, wxID_ANY, _L("Change extruder color"), "",
             [this](wxCommandEvent&) { this->change_extruder_color(); }, "funnel", menu, []() { return true; }, wxGetApp().plater());
