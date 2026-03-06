--- src/slic3r/GUI/Field.cpp.orig	2025-10-02 17:32:12 UTC
+++ src/slic3r/GUI/Field.cpp
@@ -1967,7 +1967,7 @@ void ColourPicker::on_button_click(wxCommandEvent &eve
 }
 
 void ColourPicker::on_button_click(wxCommandEvent &event) {
-#if !defined(__linux__) && !defined(__LINUX__)
+#if !defined(__linux__) && !defined(__LINUX__) && !defined(__FreeBSD__)
     if (m_clrData) {
         std::vector<std::string> colors = wxGetApp().app_config->get_custom_color_from_config();
         for (int i = 0; i < colors.size(); i++) {
@@ -1980,7 +1980,7 @@ void ColourPicker::convert_to_picker_widget(wxColourPi
 
 void ColourPicker::convert_to_picker_widget(wxColourPickerCtrl *widget)
 {
-#if !defined(__linux__) && !defined(__LINUX__)
+#if !defined(__linux__) && !defined(__LINUX__) && !defined(__FreeBSD__)
     m_picker_widget = dynamic_cast<wxColourPickerWidget*>(widget->GetPickerCtrl());
     if (m_picker_widget) {
         m_picker_widget->Bind(wxEVT_BUTTON, &ColourPicker::on_button_click, this);
@@ -1990,7 +1990,7 @@ void ColourPicker::save_colors_to_config() {
 }
 
 void ColourPicker::save_colors_to_config() {
-#if !defined(__linux__) && !defined(__LINUX__)
+#if !defined(__linux__) && !defined(__LINUX__) && !defined(__FreeBSD__)
     if (m_clrData) {
         std::vector<std::string> colors;
         if (colors.size() != CUSTOM_COLOR_COUNT) {
