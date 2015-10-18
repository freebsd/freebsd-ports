Add missing header for free()

--- Source/Core/InputCommon/ControllerInterface/Xlib/XInput2.cpp.orig	2015-10-06 19:54:17.411980007 +0000
+++ Source/Core/InputCommon/ControllerInterface/Xlib/XInput2.cpp	2015-10-06 19:54:39.087291205 +0000
@@ -4,6 +4,7 @@
 
 #include <cmath>
 #include <cstring>
+#include <cstdlib>
 #include <X11/XKBlib.h>
 
 #include "InputCommon/ControllerInterface/Xlib/XInput2.h"
