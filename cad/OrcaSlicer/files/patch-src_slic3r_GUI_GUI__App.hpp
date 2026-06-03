--- src/slic3r/GUI/GUI_App.hpp.orig	2026-03-22 17:56:38 UTC
+++ src/slic3r/GUI/GUI_App.hpp
@@ -238,7 +238,7 @@ class GUI_App : public wxApp (private)
     bool            m_app_conf_exists{ false };
     EAppMode        m_app_mode{ EAppMode::Editor };
     bool            m_is_recreating_gui{ false };
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     bool            m_opengl_initialized{ false };
 #endif
 #if defined(__WINDOWS__)
