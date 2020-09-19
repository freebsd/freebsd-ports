--- vstgui.surge/vstgui/lib/platform/linux/x11fileselector.cpp.orig	2020-06-23 22:22:42 UTC
+++ vstgui.surge/vstgui/lib/platform/linux/x11fileselector.cpp
@@ -3,6 +3,8 @@
 // distribution and at http://github.com/steinbergmedia/vstgui/LICENSE
 
 #include "../../cfileselector.h"
+#define _WITH_GETLINE // for FreeBSD 11
+#include <stdio.h> // https://github.com/surge-synthesizer/vstgui/issues/7
 #include <unistd.h>
 #include <string>
 
