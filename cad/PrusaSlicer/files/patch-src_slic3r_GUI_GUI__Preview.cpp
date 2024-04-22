--- src/slic3r/GUI/GUI_Preview.cpp.orig	2023-12-12 14:21:21 UTC
+++ src/slic3r/GUI/GUI_Preview.cpp
@@ -303,7 +303,7 @@ void Preview::load_print(bool keep_z_range)
 
 void Preview::reload_print(bool keep_volumes)
 {
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     // We are getting mysterious crashes on Linux in gtk due to OpenGL context activation GH #1874 #1955.
     // So we are applying a workaround here: a delayed release of OpenGL vertex buffers.
     if (!IsShown())
@@ -313,14 +313,14 @@ void Preview::reload_print(bool keep_volumes)
     }
 #endif /* __linux__ */
     if (
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
         m_volumes_cleanup_required || 
 #endif /* __linux__ */
         !keep_volumes)
     {
         m_canvas->reset_volumes();
         m_loaded = false;
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
         m_volumes_cleanup_required = false;
 #endif /* __linux__ */
     }
