--- src/FrequencyDialog.cpp.orig	2019-02-25 02:39:08 UTC
+++ src/FrequencyDialog.cpp
@@ -218,7 +218,7 @@ void FrequencyDialog::OnChar(wxKeyEvent& event) {
 
     if (allowed.find_first_of(c) != std::string::npos || c == WXK_DELETE || c == WXK_BACK || c == WXK_NUMPAD_DECIMAL
             || (c >= WXK_NUMPAD0 && c <= WXK_NUMPAD9)) {
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
         dialogText->OnChar(event);
         event.Skip();
 #else
