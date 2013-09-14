--- demos/FFConsoleDemo.cpp.orig	2007-01-01 02:31:15.000000000 +0300
+++ demos/FFConsoleDemo.cpp	2013-09-14 02:48:25.886226363 +0400
@@ -18,6 +18,7 @@
 ////////////////////////////////////Needed Linux Headers//////////////
 #elif defined OIS_LINUX_PLATFORM
 #  include <X11/Xlib.h>
+#  include <unistd.h> // for usleep()
    void checkX11Events();
 #endif
 //////////////////////////////////////////////////////////////////////
