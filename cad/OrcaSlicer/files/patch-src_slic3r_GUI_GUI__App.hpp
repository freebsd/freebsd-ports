--- src/slic3r/GUI/GUI_App.hpp.orig	2025-10-02 17:32:12 UTC
+++ src/slic3r/GUI/GUI_App.hpp
@@ -235,7 +235,7 @@ public:
     bool            m_app_conf_exists{ false };
     EAppMode        m_app_mode{ EAppMode::Editor };
     bool            m_is_recreating_gui{ false };
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     bool            m_opengl_initialized{ false };
 #endif
 #if defined(__WINDOWS__)
