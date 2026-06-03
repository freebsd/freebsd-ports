--- src/slic3r/GUI/GUI_Utils.hpp.orig	2026-03-22 17:56:38 UTC
+++ src/slic3r/GUI/GUI_Utils.hpp
@@ -519,7 +519,7 @@ void staticbox_remove_margin(wxStaticBox* sb);
 void staticbox_remove_margin(wxStaticBox* sb);
 #endif
 
-#if defined(__WXOSX__) || defined(__linux__)
+#if defined(__WXOSX__) || defined(__linux__) || defined(__FreeBSD__)
 bool is_debugger_present();
 #endif
 
