--- src/SFML/Window/Linux/WindowImplX11.cpp.orig	2014-04-25 17:24:48.844984881 +0400
+++ src/SFML/Window/Linux/WindowImplX11.cpp	2014-04-25 17:24:55.854171823 +0400
@@ -35,6 +35,7 @@
 #include <X11/keysym.h>
 #include <X11/extensions/Xrandr.h>
 #include <unistd.h>
+#include <libgen.h>
 #include <cstring>
 #include <sstream>
 #include <vector>
