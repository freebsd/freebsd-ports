--- Renderer/TextureManager.cpp.orig	2009-12-06 02:42:51.000000000 +0100
+++ Renderer/TextureManager.cpp
@@ -25,6 +25,7 @@
 #ifdef MACOS
 #include <dirent.h>
 #endif
+#include <sys/types.h>
 #include "TextureManager.hpp"
 #include "Common.hpp"
 #include "IdleTextures.hpp"
