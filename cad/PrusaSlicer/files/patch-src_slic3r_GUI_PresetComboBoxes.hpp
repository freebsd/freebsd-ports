--- src/slic3r/GUI/PresetComboBoxes.hpp.orig	2023-07-25 12:39:49 UTC
+++ src/slic3r/GUI/PresetComboBoxes.hpp
@@ -115,7 +115,7 @@ class PresetComboBox : public BitmapComboBox (protecte
     void validate_selection(bool predicate = false);
     void update_selection();
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     static const char* separator_head() { return "------- "; }
     static const char* separator_tail() { return " -------"; }
 #else // __linux__ 
