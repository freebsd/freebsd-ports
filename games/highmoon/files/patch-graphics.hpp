
$FreeBSD$

--- graphics.hpp.orig
+++ graphics.hpp
@@ -30,7 +30,8 @@
 #define __GRAPHICS_HPP__
 
 #include <SDL.h>
-
+#include <sstream>
+#include <string>
 #include "constants.hpp"
 
 /******************************************************************************************
