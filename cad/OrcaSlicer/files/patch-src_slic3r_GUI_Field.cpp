--- src/slic3r/GUI/Field.cpp.orig	2026-03-22 17:56:38 UTC
+++ src/slic3r/GUI/Field.cpp
@@ -825,7 +825,11 @@ void TextCtrl::BUILD() {
     auto temp = m_opt.multiline
         ? (wxWindow*)builder1.build(m_parent, wxID_ANY, "", wxDefaultPosition, size, wxTE_MULTILINE)
         : builder2.build(m_parent, "", "", "", wxDefaultPosition, size, wxTE_PROCESS_ENTER);
-    temp->SetLabel(_L(m_opt.sidetext));
+    // For multiline fields temp is a raw wxTextCtrl, whose SetLabel() asserts
+    // in wx 3.2+ (and the side text is unused there since m_combine_side_text is
+    // false). Only set the label on the TextInput composite.
+    if (!m_opt.multiline)
+        temp->SetLabel(_L(m_opt.sidetext));
 	auto text_ctrl = m_opt.multiline ? (wxTextCtrl *)temp : ((TextInput *) temp)->GetTextCtrl();
     text_ctrl->SetValue(text_value);
     temp->SetSize(size);
@@ -1190,7 +1194,7 @@ void SpinCtrl::BUILD() {
 		wxSP_ARROW_KEYS);
     temp->SetSize(size);
     temp->SetLabel(_L(m_opt.sidetext));
-    temp->GetTextCtrl()->SetLabel(text_value);
+    temp->GetTextCtrl()->ChangeValue(text_value);
     temp->SetRange(min_val, max_val);
     temp->SetValue(default_value);
     m_combine_side_text = true;
@@ -2043,7 +2047,7 @@ void ColourPicker::on_button_click(wxCommandEvent &eve
 }
 
 void ColourPicker::on_button_click(wxCommandEvent &event) {
-#if !defined(__linux__) && !defined(__LINUX__)
+#if !defined(__linux__) && !defined(__LINUX__) && !defined(__FreeBSD__)
     if (m_clrData) {
         std::vector<std::string> colors = wxGetApp().app_config->get_custom_color_from_config();
         for (int i = 0; i < colors.size(); i++) {
@@ -2056,7 +2060,7 @@ void ColourPicker::convert_to_picker_widget(wxColourPi
 
 void ColourPicker::convert_to_picker_widget(wxColourPickerCtrl *widget)
 {
-#if !defined(__linux__) && !defined(__LINUX__)
+#if !defined(__linux__) && !defined(__LINUX__) && !defined(__FreeBSD__)
     m_picker_widget = dynamic_cast<wxColourPickerWidget*>(widget->GetPickerCtrl());
     if (m_picker_widget) {
         m_picker_widget->Bind(wxEVT_BUTTON, &ColourPicker::on_button_click, this);
@@ -2066,7 +2070,7 @@ void ColourPicker::save_colors_to_config() {
 }
 
 void ColourPicker::save_colors_to_config() {
-#if !defined(__linux__) && !defined(__LINUX__)
+#if !defined(__linux__) && !defined(__LINUX__) && !defined(__FreeBSD__)
     if (m_clrData) {
         std::vector<std::string> colors;
         if (colors.size() != CUSTOM_COLOR_COUNT) {
