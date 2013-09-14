--- src/helpers/System.cpp.orig	2011-10-12 00:18:14.000000000 +0400
+++ src/helpers/System.cpp	2013-09-13 22:36:38.029229232 +0400
@@ -25,6 +25,8 @@
 #include "VExcept.h"
 #include <sstream>
 
+#include <unistd.h> // for getpid()
+
 std::vector<std::string>* System::getDisplayModes(int windowed) {
     std::vector<std::string>* modes = new std::vector<std::string>;
     SDL_Rect **sdl_modes;
