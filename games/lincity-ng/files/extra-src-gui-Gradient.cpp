--- src/gui/Gradient.cpp.orig	Fri Jul 15 19:47:11 2005
+++ src/gui/Gradient.cpp	Sat Jul 23 12:40:46 2005
@@ -28,9 +28,7 @@
 #include "Painter.hpp"
 #include "ComponentFactory.hpp"
 
-#ifdef _MSC_VER
 #define lrintf(x) (long int)x
-#endif
 
 Gradient::Gradient()
     : direction(LEFT_RIGHT)
