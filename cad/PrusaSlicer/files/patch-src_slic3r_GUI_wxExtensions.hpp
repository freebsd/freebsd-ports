--- src/slic3r/GUI/wxExtensions.hpp.orig	2023-12-12 14:21:21 UTC
+++ src/slic3r/GUI/wxExtensions.hpp
@@ -20,7 +20,7 @@
 #include <functional>
 
 
-#ifndef __linux__
+#if !defined(__linux__) && !defined(__FreeBSD__)
 void                sys_color_changed_menu(wxMenu* menu);
 #else 
 inline void         sys_color_changed_menu(wxMenu* /* menu */) {}
