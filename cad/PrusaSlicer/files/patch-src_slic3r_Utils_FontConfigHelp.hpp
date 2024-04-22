--- src/slic3r/Utils/FontConfigHelp.hpp.orig	2023-12-12 14:21:21 UTC
+++ src/slic3r/Utils/FontConfigHelp.hpp
@@ -5,7 +5,7 @@
 #ifndef slic3r_FontConfigHelp_hpp_
 #define slic3r_FontConfigHelp_hpp_
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #define EXIST_FONT_CONFIG_INCLUDE
 #endif
 
