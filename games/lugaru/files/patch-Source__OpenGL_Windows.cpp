--- ./Source/OpenGL_Windows.cpp.orig	2010-05-16 06:42:54.000000000 +0200
+++ ./Source/OpenGL_Windows.cpp	2013-12-07 18:36:52.000000000 +0100
@@ -30,6 +30,7 @@
 #undef boolean
 #endif
 
+#include <unistd.h>
 
 
 #include "Game.h"
