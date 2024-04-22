--- src/slic3r/GUI/PresetComboBoxes.hpp.orig	2023-12-12 14:21:21 UTC
+++ src/slic3r/GUI/PresetComboBoxes.hpp
@@ -119,7 +119,7 @@ class PresetComboBox : public BitmapComboBox (protecte
     void validate_selection(bool predicate = false);
     void update_selection();
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     static const char* separator_head() { return "------- "; }
     static const char* separator_tail() { return " -------"; }
 #else // __linux__ 
