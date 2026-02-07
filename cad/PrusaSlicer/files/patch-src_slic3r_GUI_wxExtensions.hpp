--- src/slic3r/GUI/wxExtensions.hpp.orig	2024-12-20 11:54:34 UTC
+++ src/slic3r/GUI/wxExtensions.hpp
@@ -21,7 +21,7 @@
 #include <boost/filesystem.hpp>
 
 
-#ifndef __linux__
+#if !defined(__linux__) && !defined(__FreeBSD__)
 void                sys_color_changed_menu(wxMenu* menu);
 #else 
 inline void         sys_color_changed_menu(wxMenu* /* menu */) {}
