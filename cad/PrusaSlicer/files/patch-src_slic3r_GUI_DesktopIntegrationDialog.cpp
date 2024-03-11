--- src/slic3r/GUI/DesktopIntegrationDialog.cpp.orig	2023-12-12 14:21:21 UTC
+++ src/slic3r/GUI/DesktopIntegrationDialog.cpp
@@ -3,7 +3,7 @@
 ///|/
 ///|/ PrusaSlicer is released under the terms of the AGPLv3 or higher
 ///|/
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #include "DesktopIntegrationDialog.hpp"
 #include "GUI_App.hpp"
 #include "GUI.hpp"
