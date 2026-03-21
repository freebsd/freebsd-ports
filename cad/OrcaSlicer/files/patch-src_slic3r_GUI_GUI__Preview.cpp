--- src/slic3r/GUI/GUI_Preview.cpp.orig	2025-10-02 17:32:12 UTC
+++ src/slic3r/GUI/GUI_Preview.cpp
@@ -335,7 +335,7 @@ void Preview::reload_print(bool keep_volumes, bool onl
 void Preview::reload_print(bool keep_volumes, bool only_gcode)
 {
     BOOST_LOG_TRIVIAL(debug) << __FUNCTION__ << boost::format(" %1%: enter, keep_volumes %2%")%__LINE__ %keep_volumes;
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     // We are getting mysterious crashes on Linux in gtk due to OpenGL context activation GH #1874 #1955.
     // So we are applying a workaround here: a delayed release of OpenGL vertex buffers.
     if (!IsShown())
@@ -345,7 +345,7 @@ void Preview::reload_print(bool keep_volumes, bool onl
     }
 #endif /* __linux__ */
     if (
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
         m_volumes_cleanup_required ||
 #endif /* __linux__ */
         !keep_volumes)
@@ -354,7 +354,7 @@ void Preview::reload_print(bool keep_volumes, bool onl
         //BBS: add m_loaded_print logic
         //m_loaded = false;
         m_loaded_print = nullptr;
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
         m_volumes_cleanup_required = false;
 #endif /* __linux__ */
     }
