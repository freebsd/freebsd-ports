--- src/slic3r/GUI/PresetComboBoxes.hpp.orig	2024-12-20 11:54:34 UTC
+++ src/slic3r/GUI/PresetComboBoxes.hpp
@@ -129,7 +129,7 @@ class PresetComboBox : public BitmapComboBox (protecte
     void validate_selection(bool predicate = false);
     void update_selection();
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     static const char* separator_head() { return "------- "; }
     static const char* separator_tail() { return " -------"; }
 #else // __linux__ 
