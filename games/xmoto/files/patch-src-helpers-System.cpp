--- src/helpers/System.cpp.orig	2014-03-29 06:14:14 UTC
+++ src/helpers/System.cpp
@@ -31,6 +31,8 @@ Foundation, Inc., 59 Temple Place, Suite
 #include <unistd.h>
 #endif
 
+#include <unistd.h> // for getpid()
+
 std::vector<std::string>* System::getDisplayModes(int windowed) {
     std::vector<std::string>* modes = new std::vector<std::string>;
     SDL_Rect **sdl_modes;
