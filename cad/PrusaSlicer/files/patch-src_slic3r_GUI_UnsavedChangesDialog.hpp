--- src/slic3r/GUI/UnsavedChangesDialog.hpp.orig	2024-06-27 09:25:47 UTC
+++ src/slic3r/GUI/UnsavedChangesDialog.hpp
@@ -49,7 +49,7 @@ class ModelNode
     wxString            m_mod_color;
     wxString            m_new_color;
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     wxIcon              get_bitmap(const wxString& color);
 #else
     wxBitmap            get_bitmap(const wxString& color);
@@ -58,7 +58,7 @@ class ModelNode
 public:
 
     bool        m_toggle {true};
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     wxIcon      m_icon;
     wxIcon      m_old_color_bmp;
     wxIcon      m_mod_color_bmp;
