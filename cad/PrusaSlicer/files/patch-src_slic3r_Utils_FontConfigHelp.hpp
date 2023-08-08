--- src/slic3r/Utils/FontConfigHelp.hpp.orig	2023-07-25 13:08:59 UTC
+++ src/slic3r/Utils/FontConfigHelp.hpp
@@ -1,7 +1,7 @@
 #ifndef slic3r_FontConfigHelp_hpp_
 #define slic3r_FontConfigHelp_hpp_
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #define EXIST_FONT_CONFIG_INCLUDE
 #endif
 
