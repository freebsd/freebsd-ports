--- demos/OISConsole.cpp.orig	2008-02-29 06:50:09.000000000 +0300
+++ demos/OISConsole.cpp	2013-09-14 02:48:43.934225837 +0400
@@ -26,6 +26,7 @@
 ////////////////////////////////////Needed Linux Headers//////////////
 #elif defined OIS_LINUX_PLATFORM
 #  include <X11/Xlib.h>
+#  include <unistd.h> // for usleep()
    void checkX11Events();
 //////////////////////////////////////////////////////////////////////
 ////////////////////////////////////Needed Mac Headers//////////////
