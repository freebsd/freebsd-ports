--- vstgui.surge/vstgui/lib/platform/linux/x11fileselector.cpp.orig	2021-04-02 18:04:51 UTC
+++ vstgui.surge/vstgui/lib/platform/linux/x11fileselector.cpp
@@ -3,6 +3,7 @@
 // distribution and at http://github.com/steinbergmedia/vstgui/LICENSE
 
 #include "../../cfileselector.h"
+#include <stdio.h> // https://github.com/surge-synthesizer/vstgui/issues/7
 #include <unistd.h>
 #include <string>
 #include <stdio.h> // Since we use getline below
