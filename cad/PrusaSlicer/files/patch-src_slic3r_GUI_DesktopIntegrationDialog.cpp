--- src/slic3r/GUI/DesktopIntegrationDialog.cpp.orig	2023-07-25 09:24:17 UTC
+++ src/slic3r/GUI/DesktopIntegrationDialog.cpp
@@ -1,4 +1,4 @@
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #include "DesktopIntegrationDialog.hpp"
 #include "GUI_App.hpp"
 #include "GUI.hpp"
