--- ./src/Gui/View3DInventorViewer.cpp.orig	Sat Feb 24 11:41:26 2007
+++ ./src/Gui/View3DInventorViewer.cpp	Sun Apr 22 00:24:07 2007
@@ -290,7 +290,7 @@
 
 void View3DInventorViewer::setEnabledFPSCounter(bool b)
 {
-#if defined (FC_OS_LINUX) || defined(FC_OS_CYGWIN)
+#if defined (FC_OS_LINUX) || defined(FC_OS_FREEBSD) || defined(FC_OS_CYGWIN)
   setenv("COIN_SHOW_FPS_COUNTER", (b?"1":"0"), 1);
 #else
   b ? _putenv ("COIN_SHOW_FPS_COUNTER=1") : _putenv ("COIN_SHOW_FPS_COUNTER=0");
