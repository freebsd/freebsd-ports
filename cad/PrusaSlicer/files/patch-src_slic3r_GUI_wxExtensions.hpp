--- src/slic3r/GUI/wxExtensions.hpp.orig	2023-07-25 13:07:41 UTC
+++ src/slic3r/GUI/wxExtensions.hpp
@@ -16,7 +16,7 @@
 #include <functional>
 
 
-#ifndef __linux__
+#if !defined(__linux__) && !defined(__FreeBSD__)
 void                sys_color_changed_menu(wxMenu* menu);
 #else 
 inline void         sys_color_changed_menu(wxMenu* /* menu */) {}
