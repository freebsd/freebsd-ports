--- src/slic3r/Utils/FontConfigHelp.hpp.orig	2024-09-18 13:39:04 UTC
+++ src/slic3r/Utils/FontConfigHelp.hpp
@@ -6,7 +6,7 @@
 #define slic3r_FontConfigHelp_hpp_
 
 #include <string>
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #define EXIST_FONT_CONFIG_INCLUDE
 #endif
 
