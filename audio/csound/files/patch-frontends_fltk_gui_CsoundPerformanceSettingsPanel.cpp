--- frontends/fltk_gui/CsoundPerformanceSettingsPanel.cpp.orig	2012-08-31 15:40:35.000000000 +0200
+++ frontends/fltk_gui/CsoundPerformanceSettingsPanel.cpp	2012-10-01 23:21:42.734591150 +0200
@@ -4,9 +4,11 @@
 #endif
 
 //CS5GUI_EXPERIMENTAL device query section left out for Windows and Mac while the problem is found
+#ifndef __FreeBSD__
 #ifdef LINUX
 #define CS5GUI_EXPERIMENTAL
 #endif
+#endif
 
 
 #include "csound.hpp"
