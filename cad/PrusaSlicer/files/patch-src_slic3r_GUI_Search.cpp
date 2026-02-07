--- src/slic3r/GUI/Search.cpp.orig	2024-12-20 11:54:34 UTC
+++ src/slic3r/GUI/Search.cpp
@@ -455,7 +455,7 @@ void OptionsSearcher::check_and_hide_dialog()
 
 void OptionsSearcher::check_and_hide_dialog()
 {
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     // Temporary linux specific workaround:
     // has_focus(search_dialog) always returns false
     // That's why search dialog will be hidden whole the time
