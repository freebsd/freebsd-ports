--- src/slic3r/GUI/PresetComboBoxes.cpp.orig	2025-10-02 17:32:12 UTC
+++ src/slic3r/GUI/PresetComboBoxes.cpp
@@ -746,7 +746,7 @@ PlaterPresetComboBox::PlaterPresetComboBox(wxWindow *p
             {
                 // In a case of a physical printer, for its editing open PhysicalPrinterDialog
                 if (m_type == Preset::TYPE_PRINTER
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
                     // To edit extruder color from the sidebar
                     || m_type == Preset::TYPE_FILAMENT
 #endif //__linux__
@@ -755,7 +755,7 @@ PlaterPresetComboBox::PlaterPresetComboBox(wxWindow *p
                 else
                     switch_to_tab();
             });
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
         edit_btn->Hide();
 #endif //__linux__
     }
@@ -914,7 +914,7 @@ void PlaterPresetComboBox::show_edit_menu()
     append_menu_item(menu, wxID_ANY, _L("Edit preset"), "",
         [this](wxCommandEvent&) { this->switch_to_tab(); }, "cog", menu, []() { return true; }, wxGetApp().plater());
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     // To edit extruder color from the sidebar
     if (m_type == Preset::TYPE_FILAMENT) {
         append_menu_item(menu, wxID_ANY, _devL("Change extruder color"), "",
