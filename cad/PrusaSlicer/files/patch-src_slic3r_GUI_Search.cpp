--- src/slic3r/GUI/Search.cpp.orig	2024-10-15 09:09:17 UTC
+++ src/slic3r/GUI/Search.cpp
@@ -455,7 +455,7 @@ void OptionsSearcher::check_and_hide_dialog()
 
 void OptionsSearcher::check_and_hide_dialog()
 {
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     // Temporary linux specific workaround:
     // has_focus(search_dialog) always returns false
     // That's why search dialog will be hidden whole the time
@@ -531,7 +531,7 @@ void OptionsSearcher::process_key_down_from_input(wxKe
         search_dialog->Hide();
     else if (search_dialog && (key == WXK_UP || key == WXK_DOWN || key == WXK_NUMPAD_ENTER || key == WXK_RETURN)) {
         search_dialog->KeyDown(e);
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
         search_dialog->SetFocus();
 #endif // __linux__
     }
