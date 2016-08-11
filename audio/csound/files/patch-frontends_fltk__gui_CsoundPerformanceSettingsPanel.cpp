--- frontends/fltk_gui/CsoundPerformanceSettingsPanel.cpp.orig	2013-01-07 12:49:35 UTC
+++ frontends/fltk_gui/CsoundPerformanceSettingsPanel.cpp
@@ -4,9 +4,11 @@
 #endif
 
 //CS5GUI_EXPERIMENTAL device query section left out for Windows and Mac while the problem is found
+#ifndef __FreeBSD__
 #ifdef LINUX
 #define CS5GUI_EXPERIMENTAL
 #endif
+#endif
 
 
 #include "csound.hpp"
