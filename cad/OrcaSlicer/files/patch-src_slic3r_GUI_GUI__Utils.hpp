--- src/slic3r/GUI/GUI_Utils.hpp.orig	2025-10-02 17:32:12 UTC
+++ src/slic3r/GUI/GUI_Utils.hpp
@@ -498,7 +498,7 @@ void staticbox_remove_margin(wxStaticBox* sb);
 void staticbox_remove_margin(wxStaticBox* sb);
 #endif
 
-#if defined(__WXOSX__) || defined(__linux__)
+#if defined(__WXOSX__) || defined(__linux__) || defined(__FreeBSD__)
 bool is_debugger_present();
 #endif
 
