--- src/slic3r/GUI/PresetComboBoxes.hpp.orig	2026-03-22 17:56:38 UTC
+++ src/slic3r/GUI/PresetComboBoxes.hpp
@@ -154,7 +154,7 @@ class PresetComboBox : public ::ComboBox // BBS (prote
     // BBS: ams
     int  update_ams_color();
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     static const char* separator_head() { return "-- "; }
     static const char* separator_tail() { return " --"; }
 #else // __linux__
