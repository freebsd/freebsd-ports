--- src/slic3r/GUI/PresetComboBoxes.hpp.orig	2025-10-02 17:32:12 UTC
+++ src/slic3r/GUI/PresetComboBoxes.hpp
@@ -131,7 +131,7 @@ class PresetComboBox : public ::ComboBox // BBS (prote
     // BBS: ams
     int  update_ams_color();
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     static const char* separator_head() { return "------- "; }
     static const char* separator_tail() { return " -------"; }
 #else // __linux__ 
