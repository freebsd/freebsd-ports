commit 8ae0abfd1d044c295c939c032790a7c4e3e960c0
Author: Christoph Moench-Tegeder <cmt@FreeBSD.org>

    enable spnav on FreeBSD, too

diff --git src/Gui/GuiApplicationNativeEventAware.cpp src/Gui/GuiApplicationNativeEventAware.cpp
index 622f38ea47..9e02558875 100644
--- src/Gui/GuiApplicationNativeEventAware.cpp
+++ src/Gui/GuiApplicationNativeEventAware.cpp
@@ -33,7 +33,7 @@
 
 
 #if defined(_USE_3DCONNEXION_SDK) || defined(SPNAV_FOUND)
-#if defined(Q_OS_LINUX)
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
   #if defined(SPNAV_USE_X11)
     #include "3Dconnexion/GuiNativeEventLinuxX11.h"
   #else
