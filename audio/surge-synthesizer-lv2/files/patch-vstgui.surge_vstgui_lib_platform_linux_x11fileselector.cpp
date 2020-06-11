--- vstgui.surge/vstgui/lib/platform/linux/x11fileselector.cpp.orig	2020-06-11 05:42:27 UTC
+++ vstgui.surge/vstgui/lib/platform/linux/x11fileselector.cpp
@@ -3,6 +3,7 @@
 // distribution and at http://github.com/steinbergmedia/vstgui/LICENSE
 
 #include "../../cfileselector.h"
+#include <stdio.h>
 #include <unistd.h>
 #include <string>
 
