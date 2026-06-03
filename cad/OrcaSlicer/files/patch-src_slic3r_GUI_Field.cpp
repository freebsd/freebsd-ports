--- src/slic3r/GUI/Field.cpp.orig	2026-03-22 17:56:38 UTC
+++ src/slic3r/GUI/Field.cpp
@@ -2043,7 +2043,7 @@ void ColourPicker::on_button_click(wxCommandEvent &eve
 }
 
 void ColourPicker::on_button_click(wxCommandEvent &event) {
-#if !defined(__linux__) && !defined(__LINUX__)
+#if !defined(__linux__) && !defined(__LINUX__) && !defined(__FreeBSD__)
     if (m_clrData) {
         std::vector<std::string> colors = wxGetApp().app_config->get_custom_color_from_config();
         for (int i = 0; i < colors.size(); i++) {
@@ -2056,7 +2056,7 @@ void ColourPicker::convert_to_picker_widget(wxColourPi
 
 void ColourPicker::convert_to_picker_widget(wxColourPickerCtrl *widget)
 {
-#if !defined(__linux__) && !defined(__LINUX__)
+#if !defined(__linux__) && !defined(__LINUX__) && !defined(__FreeBSD__)
     m_picker_widget = dynamic_cast<wxColourPickerWidget*>(widget->GetPickerCtrl());
     if (m_picker_widget) {
         m_picker_widget->Bind(wxEVT_BUTTON, &ColourPicker::on_button_click, this);
@@ -2066,7 +2066,7 @@ void ColourPicker::save_colors_to_config() {
 }
 
 void ColourPicker::save_colors_to_config() {
-#if !defined(__linux__) && !defined(__LINUX__)
+#if !defined(__linux__) && !defined(__LINUX__) && !defined(__FreeBSD__)
     if (m_clrData) {
         std::vector<std::string> colors;
         if (colors.size() != CUSTOM_COLOR_COUNT) {
